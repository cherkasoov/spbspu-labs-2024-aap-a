#include <iostream>
#include <stdexcept>
#include "destroy.hpp"
#include "printResult.hpp"
#include "createCommand.hpp"

int main()
{
  using namespace duhanina;
  Shape* shapes[10000] = {};
  size_t shapeCount = 0;
  double scalingFactor = 0;
  point_t point = { 0, 0 };
  try
  {
    inputShapes(std::cout, shapes, shapeCount);
    createScale(std::cin, shapeCount, scalingFactor, point);
    printFiguresInfo(std::cerr, shapes, shapeCount);
    processScaling(shapes, shapeCount, point, scalingFactor);
    printFiguresInfo(std::cout, shapes, shapeCount);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  if (std::cin.eof())
  {
    std::cerr << "No scale\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  destroy(shapes, shapeCount);
  return 0;
}
