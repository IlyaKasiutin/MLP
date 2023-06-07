#pragma once

#include "../matrix/matrix.h"

double sigmoid(double input);
double relu(double input);
Matrix* sigmoidPrime(Matrix* m);
Matrix* softmax(Matrix* m);