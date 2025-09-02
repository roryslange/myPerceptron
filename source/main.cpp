#include <iostream>
#include <string>
#include <random>

#include "lib.hpp"
#include "line.hpp"
#include "point.hpp"
#include "graph.hpp"
#include "perceptron.hpp"

#define NUM_POINTS 100
#define GRAPH_X_SIZE 100
#define GRAPH_Y_SIZE 100

//can probably combine these using a template
int randomInt(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min, max);
  return dist(gen);
}

float randomFloat(float min, float max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(min, max);
  return dist(gen);
}

Graph buildRandomGraph() {
    Graph graph = new Graph(GRAPH_X_SIZE, GRAPH_Y_SIZE, new Line(randomFloat(0.5,1.5), randomFloat(0.5,1.5)));
    std::vector<Point> points;
    Point point;
    Line line;
    int underCount, overCount = 0;

    // create random vector of points
    for (int i = 0; i < NUM_POINTS; i++) {
    line = graph.getLine();
    point = new Point(randomInt(1,100), randomInt(1,100));
    point.setIsUnder(line);

    point.getIsUnder() ? underCount++ : overCount++;

    points.push_back(point);
    std::printf("new point at (%d, %d) is under? %d\n", point.getX(), point.getY(), point.getIsUnder(line));
    }

    // print the line
    std::printf("y = %fx + %f\n", line.getSlope(), line.getIntercept());
    std::printf("number of points over: %d\nnumber of points under: %d\n", overCount, underCount);

    graph.setPoints(points);
    return graph;
}

void train(Graph graph, Perceptron perceptron) {
  std::vector<Point> points = graph.getPoints();
  for (int i = 0; i < points.size(); i++) {
    std::vector<float> inputs = {(float) points[i].getX(), (float) points[i].getY(), 1};
    if (perceptron.guess(inputs)) {
      std::printf("correct! on guess %d. Weights: %f, %f, %f\n", i, perceptron.getWeights()[0], perceptron.getWeights()[1], perceptron.getWeights()[2]);
    }
    else {
      std::printf("incorrect on guess %d. Weights: %f, %f, %f\n", i, perceptron.getWeights()[0], perceptron.getWeights()[1], perceptron.getWeights()[2]);
    }
    perceptron.train(inputs, points[i].getIsUnder());
  }
}

auto main() -> int
{
  auto const lib = library {};
  Graph graph = buildRandomGraph();
  Perceptron perceptron = new Perceptron({randomFloat(-1, 1), randomFloat(-5,5), randomFloat(-5,5)});

  train(graph, perceptron);

  return 0;
}
