#include "Neuron.h"

//constructor
Neuron::Neuron(double val){
    this->val = val;
    activate();
    derivative();
}

//Function to set the value of each Neuron
void Neuron::setVal(double val){
    this->val = val;
    activate();
    derivative();
}

//Activation Function
void Neuron::activate(){
    //Fast Segmoid function
    this->activatedVal = this->val / (1+abs(this->val));
}

//Derivative of Fast Segmoid
void Neuron::derivative(){
    this->derivedVal = this->activatedVal * (1 - this->activatedVal);
}