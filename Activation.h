#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <vector>
#include <functional>
#include <string>

class Activation {
public:
    static std::function<std::vector<double>(const std::vector<double>&)> getActivationFunction(const std::string& name);
private:
    static std::vector<double> sigmoid(const std::vector<double>& input);
    static std::vector<double> relu(const std::vector<double>& input);
    static std::vector<double> tanh(const std::vector<double>& input);
    //Softmax
};

#endif


