#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrix.h"

using namespace std;

class Layer{
    public:
        //constructor
        Layer(int NeuronNumber);
        void setValue(int i , double v);
        //LayerToMatrix makes a matrix representation for a given Layer
        Matrix *LayerToMatrix();
        Matrix *LayerToMatrixActivatedValue();
        Matrix *LayerToMatrixDerivedValue();
        //Number of neurons in each layer
        vector<Neuron *> getNeurons() {return this->neurons;};
        void setNeurons(vector<Neuron *>neurons){this->neurons = neurons;};
    private:
        int NeuronNumber;

        //Vector of Neurons
        vector<Neuron*> neurons;
};

#endif