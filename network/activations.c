#include "activations.h"

#include <math.h>
#include "../matrix/operations.h"

double sigmoid(double input) {
	return 1.0 / (1 + exp(-1 * input));
}

double relu(double input) {
	int beta = 0.01;
    return (input > 0) ? input : beta * input;
}

Matrix* sigmoidPrime(Matrix* m) {
	Matrix* ones = matrix_create(m->rows, m->cols);
	matrix_fill(ones, 1);
	Matrix* subtracted = subtract(ones, m);
	Matrix* multiplied = multiply(m, subtracted);
	matrix_free(ones);
	matrix_free(subtracted);
	return multiplied;
}

Matrix* reluPrime(Matrix* m) {
	Matrix* res = matrix_create(m->rows, m->cols);
	double prime = 0.0;
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			prime = (m->entries[i][j] > 0) ? 1 : 0.01;
			res->entries[i][j] = prime;
		}
	}
	return res;
}

Matrix* softmax(Matrix* m) {
	double total = 0;
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			total += exp(m->entries[i][j]);
		}
	}
	Matrix* mat = matrix_create(m->rows, m->cols);
	for (int i = 0; i < mat->rows; i++) {
		for (int j = 0; j < mat->cols; j++) {
			mat->entries[i][j] = exp(m->entries[i][j]) / total;
		}
	}
	return mat;
}