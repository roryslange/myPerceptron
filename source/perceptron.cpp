#include "perceptron.hpp"


Perceptron::Perceptron() {
    this->weight1 = 0;
    this->weight2 = 0;
}

Perceptron::Perceptron(float weight1, float weight2) {
    this->weight1 = weight1;
    this->weight2 = weight2;
}

Perceptron::Perceptron(Perceptron* perceptron) {
    this->weight1 = perceptron->getWeight1();
    this->weight2 = perceptron->getWeight2();
}

float Perceptron::getWeight1() {
    return weight1;
}

void Perceptron::setWeight1(float weight1) {
    this->weight1 = weight1;
}

float Perceptron::getWeight2() {
    return weight2;
}

void Perceptron::setWeight2(float weight2) {
    this->weight2 = weight2;
}