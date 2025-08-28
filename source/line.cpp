#include "line.hpp"

Line::Line() {
    this->intercept = 0;
    this->slope = 0;
}

Line::Line(float slope, float intercept) {
    this->intercept = intercept;
    this->slope = slope;
}

Line::Line(Line* line) {
    this->intercept = line->getIntercept();
    this->slope = line->slope;
}

void Line::setIntercept(float intercept) {
    this->intercept = intercept;
}

float Line::getIntercept() {
    return this->intercept;
}

void Line::setSlope(float slope) {
    this->slope = slope;
}

float Line::getSlope() {
    return this->slope;
}

float Line::calculateY(int x) {
    return slope * (float) x + intercept;
}

bool Line::isUnder(Point point) {
    return ((float) point.getY()) <= calculateY(point.getX());
}