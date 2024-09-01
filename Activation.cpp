#include "Activation.h"
#include <cmath>
#include <algorithm>
#include <iostream>

// Factory method implementation
std::function<std::vector<double>(const std::vector<double>&)> Activation::getActivationFunction(const std::string& name) {
    if (name == "sigmoid") {
        return sigmoid;
    }
    else if (name == "relu") {
        return relu;
    }
    else if (name == "tanh") {
        return tanh;
    }
    else {
        throw std::invalid_argument("Unknown activation function: " + name);
    }
}

// Sigmoid function
std::vector<double> Activation::sigmoid(const std::vector<double>& input) {
    std::vector<double> output;
    output.reserve(input.size());
    for (double x : input) {
        output.push_back(1.0 / (1.0 + std::exp(-x)));
    }
    return output;
}

// ReLU function
std::vector<double> Activation::relu(const std::vector<double>& input) {
    std::vector<double> output;
    output.reserve(input.size());
    for (double x : input) 
        output.push_back(std::max(0.0, x));
    
    return output;
}

// Tanh function
std::vector<double> Activation::tanh(const std::vector<double>& input) {
    std::vector<double> output;
    output.reserve(input.size());
    for (double x : input) 
        output.push_back(std::tanh(x));
    return output;
}


//Softmax
