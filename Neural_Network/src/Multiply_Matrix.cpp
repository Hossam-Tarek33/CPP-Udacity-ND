#include "Multiply_Matrix.h"

MultiplyMatrix::MultiplyMatrix(Matrix *a, Matrix *b){
    this->a = a;
    this->b = b;

    if(a->getColumnsNumber()!= b->getRowsNumber()){
        cerr<<"A_rows: "<<a->getRowsNumber() <<" !=B_cals: "<<b->getColumnsNumber()<<"\n";
        assert(false);
    }
    this->c = new Matrix(a->getRowsNumber(), b->getColumnsNumber(), false);
}

Matrix * MultiplyMatrix::execute(){
    for(int i=0; i<a->getRowsNumber(); i++){
        for(int j=0; j<b->getColumnsNumber(); j++){
            for(int k=0; k<b->getRowsNumber(); k++){
                double p = this->a->getValue(i,k) * this->b->getValue(k,j);
                double newVal = this->c->getValue(i,j) + p;
                this->c->setValue(i, j, newVal);
            }
        }
    }
    return this->c;
}