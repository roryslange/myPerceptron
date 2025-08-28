#pragma once
#include "point.hpp"

class Line {
    private:
        float intercept;
        float slope;

        float calculateY(int x); // calculates y value of a function in y = mx + b

    public:
        Line();
        Line(float slope, float intercept);
        Line(Line* line);
        ~Line() = default;

        void setIntercept(float intercept);
        float getIntercept();
        void setSlope(float slope);
        float getSlope();
        bool isUnder(Point point);
};