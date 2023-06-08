#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "images/image.h"
#include "network/activations.h"
#include "network/nn.h"
#include "matrix/matrix.h"
#include "matrix/operations.h"

int main() {
	srand(time(NULL));

	//TRAINING
	int number_imgs = 1000;
	Img** imgs = csv_to_imgs("./data/mnist_train.csv", number_imgs);
	img_print(imgs[13]);
	NeuralNetwork* net = network_create(784, 300, 10, 0.1);
	network_train_batch_imgs(net, imgs, number_imgs);
	network_save(net, "testing_net");

	// PREDICTING
	// int number_imgs = 1000;
	// Img** imgs = csv_to_imgs("data/mnist_test.csv", number_imgs);
	// NeuralNetwork* net = network_load("testing_net");
	// double score = network_predict_imgs(net, imgs, number_imgs);
	// printf("Score: %1.5f\n", score);

	imgs_free(imgs, number_imgs);
	network_free(net);
	return 0;
}