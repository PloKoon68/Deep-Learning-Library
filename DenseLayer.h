#ifndef DENSE_LAYER_H
#define DENSE_LAYER_H

#include <vector>
#include "Layer.h" 

class DenseLayer : public Layer {
private:
    int input_size;
    int output_size;

    std::vector<std::vector<double>> weights;
    std::vector<double> bias;

    std::vector<std::vector<double>> weightDerivatives;
    std::vector<double> biasDerivatives;

    void initParameters() override;
    void initDerivatives() override;

public:
    DenseLayer(const int& input_size, const int& output_size);
    std::vector<double> forward(const std::vector<double>& input) override;
    std::vector<double> backward(const std::vector<double>& input) override;

    void display() const override;
};

#endif 
