#include <iostream>
#include <string>

#include "lib.hpp"
#include "perceptron.h"

auto main() -> int
{
  auto const lib = library {};
  auto const message = "Hello from " + lib.name + "!";
  std::cout << message << '\n';

  Perceptron* testp = new Perceptron();

  return 0;
}
