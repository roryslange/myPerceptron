#include "graph.hpp"

Graph::Graph() {
    this->line = new Line();
    this->xSize = 0;
    this->ySize = 0;
    this->points = {};
    this->numPoints = this->points.size();
}

Graph::Graph(int xSize, int ySize, std::vector<Point> points, Line line) {
    this->xSize = xSize;
    this->ySize = ySize;
    this->points = points;
    this->line = line;
    this->numPoints = points.size();
}

Graph::Graph(int xSize, int ySize, Line line) {
    this->xSize = xSize;
    this->ySize = ySize;
    this->line = line;
}

Graph::Graph(Graph* graph) {
    this->numPoints = graph->getNumberOfPoints();
    this->xSize = graph->getXSize();
    this->ySize = graph->getYSize();
    this->points = graph->getPoints();
    this->line = graph->getLine();
}

std::vector<Point> Graph::getPoints() {
    return this->points;
}

void Graph::setPoints(std::vector<Point> points) {
    this->points = points;
}

int Graph::getXSize() {
    return this->xSize;
}

void Graph::setXSize(int xSize) {
    this->xSize = xSize;
}

int Graph::getYSize() {
    return this->ySize;
}

void Graph::setYSize(int ySize) {
    this->ySize = ySize;
}

Line Graph::getLine() {
    return this->line;
}

void Graph::setLine(Line line) {
    this->line = line;
}

int Graph::getNumberOfPoints() {
    return this->numPoints;
}
