#include "Matrix.h"
#include <random>
using namespace std;

double Matrix::generateRandomNumber(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0,1);

    return dis(gen);
}

Matrix::Matrix(int RowsNumber , int ColumnsNumber , bool SetRandom){
    this->RowsNumber = RowsNumber;
    this->ColumnsNumber = ColumnsNumber;
    for(int i =0; i<RowsNumber ; i++){
        vector<double> ColumnValues;
        for(int j = 0 ; j<ColumnsNumber ; j++){
            double value = 0.0;
            if(SetRandom == true) { value = this->generateRandomNumber();}
            ColumnValues.push_back(value);
        }
        MatrixValues.push_back(ColumnValues);
    }
}

void Matrix::setValue(int r, int c, double v){
    this->MatrixValues.at(r).at(c) = v;
}

double Matrix::getValue(int r, int c){
    return this->MatrixValues.at(r).at(c);
}

Matrix *Matrix::transpose(){
    Matrix *m = new Matrix(this->ColumnsNumber ,this->RowsNumber ,false);
    for(int i =0; i<RowsNumber ; i++){
        for(int j = 0 ; j<ColumnsNumber ; j++){
            m->setValue(j, i, this->getValue(i,j));
        }
    }
    return m;
}

void Matrix::PrintToConsole(){
    for(int i =0; i<RowsNumber ; i++){
        for(int j = 0 ; j<ColumnsNumber ; j++){
            cout<<this->MatrixValues.at(i).at(j)<<"\t";
        }
        cout<<"\n";
    }
}
