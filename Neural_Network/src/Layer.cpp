#include "Layer.h"

Layer::Layer (int NeuronNumber){
    this->NeuronNumber = NeuronNumber;
    for(int i =0 ; i<NeuronNumber ; i++){
        //create an instance of class neuron and set its value to 0.0
        Neuron *n = new Neuron(0.0);
        //add the neuron to the neurons vector
        this->neurons.push_back(n);
    }
}

void Layer::setValue(int i, double v){
    //set the value of specific index to value double v
    this->neurons.at(i)->setVal(v);
    
}

//these functions transform the layer to matrix representation
Matrix *Layer::LayerToMatrix(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->getVal());
    }
    return m;
}

Matrix *Layer::LayerToMatrixActivatedValue(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->getActivatedVal());
    }
    return m;
}

Matrix *Layer::LayerToMatrixDerivedValue(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->getDerivedVal());
    }
    return m;
}

