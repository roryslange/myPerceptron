#pragma once
#include "line.hpp"

class Point {
    private:
        int xCoordinate;
        int yCoordinate;
        bool isUnder; // arbitrary boolean to update when a point is under or over line we are trying to estimate

    public:
        Point();
        Point(int x, int y);
        Point(int x, int y, bool isUnder);
        Point(Point* point);
        ~Point() = default;

        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        bool getIsUnder();
        void setIsUnder(bool isUnder);
        bool getIsUnder(Line line);
        void setIsUnder(Line line);
        
};