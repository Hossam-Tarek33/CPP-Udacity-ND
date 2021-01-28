#include "Network.h"
#include "Layer.h"

Network::Network(vector<int> topology){
    this->topology = topology;
    for(int i =0; i<topology.size(); i++){
        //create a layer in the layer vector corresponding to size of topology
        Layer *l = new Layer(topology.at(i));
        this->Layers.push_back(l);
    }
    //the weight matrix is the topolgy size -1 
    for(int i=0; i<(topology.size()-1) ; i++){
        //create a vector of matrix for each layer
        Matrix *m = new Matrix(topology.at(i), topology.at(i+1), true);
        //add the created vector of matrix to Weights vector
        this-> Weights.push_back(m);
    }
}

//this function sets the inputs of the neurons for input layer
void Network::setInputValues(std::vector<double> input){
    this->input = input;
    for(int i; i<input.size(); i++){
        this->Layers.at(0)->setValue(i , input.at(i));
    }
}

void Network::PrintToConsole(){
    for(int i=0; i<this->Layers.size(); i++){
        cout<<"Layer "<<i<<":\n";
        if(i==0){
            //this is the input layer only
            Matrix *m = this->Layers.at(i)->LayerToMatrix();
            m->PrintToConsole();
        }
        else {
            //this is for any other layer
            Matrix *m = this->Layers.at(i)->LayerToMatrixActivatedValue();
            m->PrintToConsole();
        }
        cout<<"--------------------------"<<"\n";
        //printing the weights
        if(i < this->Layers.size() -1){
            cout<<"Wieghts Values:"<<i<<"\n";
            this->getWeightMatrix(i)->PrintToConsole();
        }
        cout<<"--------------------------"<<"\n";
    }
}

void Network::feedForward(){
    for(int i=0; i<(this->Layers.size()-1);i++){
        Matrix *a = this->getNeuronMatrix(i);

        if(i != 0){
            a =this->getActivatedNeuronMatrix(i);
        }
        Matrix *b=this->getWeightMatrix(i);
        Matrix *c= (new MultiplyMatrix(a,b))->execute();
        
        //vector<double> vals;
        for(int c_index = 0;c_index < c->getColumnsNumber(); c_index++){
            //vals.push_back(c->getValue(0, c_index));
            this->setNeuronValue(i+1, c_index, c->getValue(0,c_index));
        }
    }
}