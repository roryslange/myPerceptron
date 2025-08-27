#include <iostream>
#include <string>

#include "lib.hpp"
#include "line.hpp"
#include "point.hpp"
#include "graph.hpp"


auto main() -> int
{
  auto const lib = library {};

  // auto testLine = std::make_unique<Line>(2, 4.5);
  Line testLine = new Line(2.1, 4.5);
  Point testPoint = new Point(3, 4);
  Point testPoint2 = new Point(4, 5);

  std::vector<Point> points;
  points.push_back(testPoint2);
  points.push_back(testPoint);

  Graph testGraph = new Graph(10, 10, points, testLine);
  

  std::printf("a line with slope %f and intercept %f\n", testLine.getSlope(), testLine.getIntercept());
  std::printf("and a point at coordinates (%d, %d)\n", testPoint.getX(), testPoint.getY());
  std::printf("graph of size %d by %d\n", testGraph.getXSize(), testGraph.getYSize());


  return 0;
}
