#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "perceptron" ? 0 : 1;
}
