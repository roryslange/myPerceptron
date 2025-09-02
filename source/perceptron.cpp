#include "perceptron.hpp"
#define LEARNING_RATE 0.05


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

void Perceptron::train(std::vector<float> inputs, bool target) {
    bool error = this->guess(inputs) && target;

    for (int i = 0; i < inputs.size(); i++) {
        // this->weights[i] += error ? 0 : inputs[i] * LEARNING_RATE;
        if (error && !target) {
            //point over, guess under
            this->weights[i] += inputs[i] * LEARNING_RATE;
        }
        else if (!error && target) {
            //point under, guess over
            this->weights[i] += inputs[i] * LEARNING_RATE * -1;
        }
        //else no change
    }
}