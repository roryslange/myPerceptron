#include <vector>
#include "point.h"

class Graph {
    private:
        int numPoints;
        int xSize;
        int ySize; 
        std::vector<Point>* points;

    public:
        Graph();
        Graph(int xSize, int ySize, std::vector<Point>& points);
        Graph(int xSize, int ySize, int numPoints);
        Graph(Graph* graph);
        ~Graph() = default;

        std::vector<Point> getPoints();
        void setPoints(std::vector<Point>& points);
        int getNumberOfPoints();
        virtual void draw() final;

};