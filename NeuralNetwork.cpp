#include "NeuralNetwork.h"


NeuralNetwork::NeuralNetwork(std::vector<int> layerSizes, int inputSize) {
	int input_size = inputSize;
	for (int layerSize : layerSizes) {
		layers.push_back(new DenseLayer(input_size, layerSize));
		input_size = layerSize;
	}
}
std::vector<double> NeuralNetwork::train(std::vector<double>& inputLayer) {
	std::vector<double> stuff = inputLayer;

	//forward propagation
	for (Layer* layer : layers) {
		stuff = layer->forward(stuff);
	}


	return stuff;
}

/*
std::vector<double> NeuralNetwork::forwardPropagation(std::vector<double>& input, Layer* layer) {

}

std::vector<double> NeuralNetwork::backwardPropagation(std::vector<double>& input, Layer* layer) {

}*/