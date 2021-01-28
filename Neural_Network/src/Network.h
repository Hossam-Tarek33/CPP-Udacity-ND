#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrix.h"
#include "Layer.h"
#include "Multiply_Matrix.h"

class Network {
    public:
        //constructor
        Network(vector<int> topology);
        //this vector to set the values of input neurons in the input layer
        void setInputValues(vector<double> input);
        void feedForward();
        void PrintToConsole();

        //some matrix operations used in layers
        Matrix *getNeuronMatrix(int index){return this->Layers.at(index)->LayerToMatrix();}
        Matrix *getActivatedNeuronMatrix(int index){return this->Layers.at(index)->LayerToMatrixActivatedValue();}
        Matrix *getDerivedNeuronMatrix(int index){return this->Layers.at(index)->LayerToMatrixDerivedValue();}
        Matrix *getWeightMatrix(int index){return this->Weights.at(index);}

        void setNeuronValue(int indexLayer,int indexNeuron, double val){this->Layers.at(indexLayer)->setValue(indexNeuron,val);}
    private:
        //topolgy is the number of neurons in each layer
        vector<int> topology;
        vector<Layer *> Layers;
        vector<Matrix*> Weights;
        vector<double> input;
};
#endif