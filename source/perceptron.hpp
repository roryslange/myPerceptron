#pragma once

class Perceptron {
    private:
        float weight1;
        float weight2;

    public:
        Perceptron();
        Perceptron(float weight1, float weight2);
        Perceptron(Perceptron* Perceptron);
        ~Perceptron() = default;
        float getWeight1();
        void setWeight1(float weight1);
        float getWeight2();
        void setWeight2(float weight2);
};