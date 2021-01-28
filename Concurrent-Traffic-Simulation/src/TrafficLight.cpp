#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <queue>
#include <future>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */

 
template <typename T>
T MessageQueue<T>::receive()
{
    // A lock which is passed to the condition variable should be created
	std::unique_lock<std::mutex> u_lock(_mutex);
	_condition.wait(u_lock, [this] { return !_queue.empty(); });
    //remove the last element in _queue
    T Currentmsg = std::move(_queue.back());
	_queue.pop_back();
	return Currentmsg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.emplace_back(msg);
    _condition.notify_one();
}


/* Implementation of class "TrafficLight" */


TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    while (true)
    {
        //reduce CPU usage by sleeping 1 millisec each iteration
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        //wait until green light comes, then recive the msg from queue
        auto Currentmsg = _queue.receive();
        if(Currentmsg == green){
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}


// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    //Cycle duration between 4 and 6 sec
    std::uniform_int_distribution<int> dist(4000, 6000);
    int cycle = dist(gen);

    auto lastUpdateTime = std::chrono::system_clock::now();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        auto time_sec = std::chrono::duration_cast<std::chrono::milliseconds>
                                (std::chrono::system_clock::now() - lastUpdateTime);
        int duration = time_sec.count();
        
        if(duration >= cycle){
            //Toggling the light
            if (_currentPhase == red) _currentPhase = green;
			else _currentPhase = red;

            auto sent = std::async(std::launch::async, 
                                    &MessageQueue<TrafficLightPhase>::send,
                                    &_queue,
                                    std::move(_currentPhase));
            sent.wait();

            lastUpdateTime = std::chrono::system_clock::now();
            cycle = dist(gen);
        }
        
    }
}

