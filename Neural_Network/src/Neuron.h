#ifndef NEURON_H
#define NEURON_H

#include <iostream>
using namespace std;

class Neuron {
    public:
        Neuron(double val);
        void setVal(double val);
        void activate();
        void derivative();

        //getters
        double getVal(){ return this -> val;}
        double getActivatedVal(){ return this-> activatedVal;}
        double getDerivedVal() { return this-> derivedVal;}
    
    private:
        double val;
        double activatedVal;
        double derivedVal;
};

#endif
