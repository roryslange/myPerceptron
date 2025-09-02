#include "perceptron.hpp"


Perceptron::Perceptron() {
    this->weights = {};
}

Perceptron::Perceptron(std::vector<float> weights) {
    this->weights = weights;
}

Perceptron::Perceptron(Perceptron* perceptron) {
    this->weights = perceptron->weights;
}

std::vector<float> Perceptron::getWeights() {
    return this->weights;
}

void Perceptron::setWeights(std::vector<float> weights) {
    this->weights = weights;
}

float Perceptron::sum(std::vector<float> inputs) {
    float sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += inputs[i] * weights[i];
    }
    return sum;
}

bool Perceptron::guess(std::vector<float> inputs) {
    return this->sum(inputs) < 0;
}