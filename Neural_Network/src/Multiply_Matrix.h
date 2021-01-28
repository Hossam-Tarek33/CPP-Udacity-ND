#ifndef MULTIPLY_MATRIX_H
#define MULTIPLY_MATRIX_H

#include <iostream>
#include <vector>
#include <assert.h>
#include "Matrix.h"

using namespace std;

class MultiplyMatrix{
    public:
        MultiplyMatrix(Matrix *a, Matrix *b);
        //return the result of multiplication
        Matrix *execute();

    private:
        Matrix *a;
        Matrix *b;
        Matrix *c;
};

#endif