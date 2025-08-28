#include <iostream>
#include <string>
#include <random>

#include "lib.hpp"
#include "line.hpp"
#include "point.hpp"
#include "graph.hpp"

#define NUM_POINTS 100

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

auto main() -> int
{
  auto const lib = library {};
  
  std::vector<Point> points;
  Line line = new Line(randomFloat(0.5,1.5), randomFloat(0.5,1.5));
  Point point;
  int underCount = 0;
  int overCount = 0;

  // create random vector of points
  for (int i = 0; i < NUM_POINTS; i++) {
    point = new Point(randomInt(1,100), randomInt(1,100));
    point.setIsUnder(line);

    point.getIsUnder() ? underCount++ : overCount++;

    points.push_back(point);
    std::printf("new point at (%d, %d) is under? %d\n", point.getX(), point.getY(), point.getIsUnder(line));
  }

  // print the line
  std::printf("y = %fx + %f\n", line.getSlope(), line.getIntercept());
  std::printf("number of points over: %d\nnumber of points under: %d\n", overCount, underCount);

  return 0;
}
