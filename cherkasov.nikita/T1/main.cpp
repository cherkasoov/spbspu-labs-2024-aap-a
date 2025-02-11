#include <iostream>
#include <iomanip>
#include <string>
#include "shapeFactory.hpp"
#include "procesShape.hpp"
#include "makesShape.hpp"

int main()
{
  cherkasov::Shape* shapes[10000] = {};
  std::string inputCommand;
  size_t shapeCount = 0;
  bool invalidInput = false;
  cherkasov::point_t p = {0.0, 0.0};
  double scalingFactor = 0.0;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      std::cin >> p.x >> p.y >> scalingFactor;
      break;
    }
    else if (std::cin.eof())
    {
      cherkasov::deleteShapes(shapes, shapeCount);
      std::cerr << "EOF encountered\n";
      return 1;
    }
    else
    {
      cherkasov::Shape* shape = cherkasov::createShape(inputCommand, std::cin);
      if (shape)
      {
        shapes[shapeCount++] = shape;
      }
    }
  }
  if (shapeCount == 0)
  {
    std::cerr << "no shapes specified\n";
    return 1;
  }
  if (!scalingRequested)
  {
    cherkasov::deleteShapes(shapes, shapeCount);
    std::cerr << "scaling was not specified\n";
    return 1;
  }
  if (invalidInput)
  {
    std::cerr << "invalid input encountered\n";
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << cherkasov::getSumArea(shapes, shapeCount);
  cherkasov::getCoordinates(shapes, shapeCount);
  cherkasov::getScaling(shapes, shapeCount, p, scalingFactor);
  std::cout << cherkasov::getSumArea(shapes, shapeCount) << "\n";
  cherkasov::getCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
