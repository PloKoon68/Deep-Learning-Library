#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

#include "Layer.h"
#include "DenseLayer.h"

class NeuralNetwork {
private:

public:
    std::vector<Layer*> layers;
    NeuralNetwork(std::vector<int> layerSizes, int inputSize);
    std::vector<double> train(std::vector<double>& inputLayer);
    std::vector<double> forwardPropagation(std::vector<double>& input, Layer* layer);
    std::vector<double> backwardPropagation(std::vector<double>& input, Layer* layer);

};

#endif 
