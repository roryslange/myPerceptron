#include "point.hpp"

Point::Point() {
    this->xCoordinate = 0;
    this->yCoordinate = 0;
    this->isUnder = false;
}

Point::Point(int x, int y) {
    this->xCoordinate = x;
    this->yCoordinate = y;
    this->isUnder = false;
}

Point::Point(Point* point) {
    this->xCoordinate = point->getX();
    this->yCoordinate = point->getY();
    this->isUnder = point->getIsUnder();
}

int Point::getX() {
    return this->xCoordinate;
}

void Point::setX(int x) {
    this->xCoordinate = x;
}

int Point::getY() {
    return this->yCoordinate;
}

void Point::setY(int y) {
    this->yCoordinate = y;
}

bool Point::getIsUnder() {
    return this->isUnder;
}

void Point::setIsUnder(bool isUnder) {
    this->isUnder = isUnder;
}

void Point::setIsUnder(Line line) {
    this->isUnder = getIsUnder(line);
}

bool Point::getIsUnder(Line line) {
    return (float) this->yCoordinate <= line.getSlope() * (float) this->xCoordinate + line.getIntercept(); //simple y = mx+b
}

