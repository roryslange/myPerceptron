#pragma once
#include <vector>
#include "point.hpp"
#include "line.hpp"

class Graph {
    private:
        int numPoints;
        int xSize;
        int ySize; 
        std::vector<Point>* points;
        Line line;


    public:
        Graph();
        Graph(int xSize, int ySize, std::vector<Point>& points, Line line);
        Graph(int xSize, int ySize, int numPoints, Line line);
        Graph(Graph* graph);
        ~Graph() = default;

        std::vector<Point> getPoints();
        void setPoints(std::vector<Point>& points);
        int getXSize();
        void setXSize();
        int getYSize();
        void setYSize();
        int getNumberOfPoints();
        void buildGraph();
        // virtual void draw() final;
};