// Online C++ compiler to run C++ program online
#include "Activation.h"
#include "DenseLayer.h"
#include "NeuralNetwork.h"

#include <iostream>
using namespace std;



int main() {
    /*
    std::vector<double> input = { 0.95, -1.2, 3.3 };
    auto sigmoid = Activation::getActivationFunction("sigmoid");
    auto result = sigmoid(input);
    */

    /*
    DenseLayer* layer1 = new DenseLayer(4, 3);
    DenseLayer* layer2 = new DenseLayer(3, 2);

    layer1->display();
    cout << "-----------------" << endl;
    layer2->display();

    vector<double> input = {4, 2, 1, 0.2};
    vector<double> output1 = layer1->forward(input);
    vector<double> output2 = layer2->forward(output1);


    for (double i : output2)
        cout << i << " ";

        */

    vector<double> input = { 4, 2, 1.5, 0.2 };

    vector<int> layerSizes = {3, 4, 2, 1};
    NeuralNetwork* nn = new NeuralNetwork(layerSizes, input.size());

    for (Layer* layer : nn->layers) {
        layer->display();
    }

    nn->train(input);

    return 0;
}