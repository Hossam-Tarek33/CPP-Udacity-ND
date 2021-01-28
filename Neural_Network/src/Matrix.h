#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
        //constructor .. if SetRandom is true then the matrix will be set with random Numbers
        Matrix(int RowsNumber , int ColumnsNumber , bool SetRandom);
        //Pointer to matrix (Transpose the Matrix)
        Matrix *transpose();
        //Function to generate random values for the matris(if SetRandom is True)
        double generateRandomNumber();
        //Function To Print Matrix Values on Console
        void PrintToConsole();
        //setter
        void setValue (int r, int c, double v);
        //getter
        double getValue (int r, int c);
        int getRowsNumber(){return this->RowsNumber;}
        int getColumnsNumber(){return this->ColumnsNumber;}
    private:
        int RowsNumber;
        int ColumnsNumber;
        bool SetRandom;

        //the values inside the matrix
        vector<vector<double>> MatrixValues;

};
#endif