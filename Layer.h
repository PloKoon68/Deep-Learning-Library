#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~Layer() {}

    virtual void initParameters() = 0;
    virtual void initDerivatives() = 0;
    virtual std::vector<double> forward(const std::vector<double>& input) = 0;
    virtual std::vector<double> backward(const std::vector<double>& input) = 0;

    //add backward

    // Pure virtual function to display the layer's details
    virtual void display() const = 0;
};


#endif 
