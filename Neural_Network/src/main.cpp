#include <iostream>
#include "Neuron.h"
#include "Matrix.h"
#include "Network.h"
#include "Layer.h"

using namespace std;

int main (){
    vector<int> topology;
    int x,y;
    cout<<"Insert Number of Neurons in Input Layer: ";
    cin>>x;
    topology.push_back(x);
    cout<<"Insert Number of Neurons in Hidden Layer: ";
    cin>>y;
    topology.push_back(y);
    topology.push_back(1);

    vector<double> input;
    double a[x]={};
    cout<<"Enter the values of Neurons of Input Layer"<<"\n";
    for(int i =0; i < x; i++){
        cin>>a[i];
        input.push_back(a[i]);
    }
    
    Network *nn = new Network(topology);
    nn->setInputValues(input);
    nn->feedForward();
    cout<<"===============RESULT==============="<<"\n";
    nn->PrintToConsole();
    return 0;
}