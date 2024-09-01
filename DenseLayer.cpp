#include "DenseLayer.h"
#include <iostream>
#include <cstdlib> // For rand()

// Implementation of DenseLayer methods
DenseLayer::DenseLayer(const int& input_size, const int& output_size)
    : input_size(input_size), output_size(output_size) {
    initParameters();
    initDerivatives();
}

void DenseLayer::initParameters() {
    // Initialize weights with random values
    weights.resize(output_size, std::vector<double>(input_size));
    for (int i = 0; i < output_size; ++i) 
        for (int j = 0; j < input_size; ++j) 
            weights[i][j] = static_cast<double>(rand()) / RAND_MAX;
    //Initialize bias with 0
    bias.resize(output_size, 0.0);
}
void DenseLayer::initDerivatives() {
    // Initialize derivatives with 0 value
    weightDerivatives.resize(output_size, std::vector<double>(input_size, 0));
    biasDerivatives.resize(output_size, 0.0);
}


//take input a[l-1], return output a[l]
std::vector<double> DenseLayer::forward(const std::vector<double>& input) {
    std::vector<double> output(output_size, 0.0);
    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            output[i] += input[j] * weights[i][j];
            std::cout << input[j] << " * " << weights[i][j] << " + ";
        }
        std::cout << "= " << output[i] << std::endl;
        output[i] += bias[i];
    }
    std::cout << "end \n\n" << std::endl;

    return output;
}
std::vector<double> DenseLayer::backward(const std::vector<double>& input) {
    std::vector<double> output(output_size, 0.0);
    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            output[i] += input[j] * weights[i][j];
            std::cout << input[j] << " * " << weights[i][j] << " + ";
        }
        std::cout << "= " << output[i] << std::endl;
    }
    return output;
}

void DenseLayer::display() const {
    std::cout << "-------------------------\n";

    std::cout << "Dense Layer Weights:\n";
    for (const auto& row : weights) {
        for (double w : row) 
            std::cout << w << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Dense Layer Biases:\n";
    for (const auto& b : bias)
        std::cout << b << " ";
    std::cout << std::endl;
    std::cout << "-------------------------\n";
}


