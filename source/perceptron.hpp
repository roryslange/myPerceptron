#pragma once

#include <vector>

class Perceptron {
    private:
        std::vector<float> weights;

        float sum(std::vector<float> inputs);

    public:
        Perceptron();
        Perceptron(std::vector<float> weights);
        Perceptron(Perceptron* Perceptron);
        ~Perceptron() = default;
        std::vector<float> getWeights();
        void setWeights(std::vector<float> weights);

        int guess(std::vector<float> inputs);

};