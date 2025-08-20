#include <iostream>
#include <string>

#include "lib.hpp"
#include "perceptron.hpp"

auto main() -> int
{
  auto const lib = library {};

  for (int i = 0; i <= 100; i++) {
    std::cout << "*";
  }

  auto testp = std::make_unique<Perceptron>();

  return 0;
}
