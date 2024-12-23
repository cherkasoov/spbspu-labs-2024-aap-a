#include "InputHandler.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include <iostream>
#include <algorithm>

cherkasov::Shape* parseShapeInput(const std::string& inputCommand, std::istream& input, bool& invalidInput)
{
  if (inputCommand == "RECTANGLE")
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    input >> x1 >> y1 >> x2 >> y2;
    if (!input || x1 >= x2 || y1 >= y2)
    {
      invalidInput = true;
      return nullptr;
    }
    return new cherkasov::Rectangle(x1, y1, x2, y2);
  }
  else if (inputCommand == "SQUARE")
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double length = 0.0;
    input >> x1 >> y1 >> length;
    if (!input || length <= 0)
    {
      invalidInput = true;
      return nullptr;
    }
    return new cherkasov::Square(x1, y1, length);
  }
  else if (inputCommand == "PARALLELOGRAM")
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double x3 = 0.0;
    double y3 = 0.0;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (!input || (x1 == x3 && y2 == y3) || (x2 == x3 && y1 == y3))
    {
      invalidInput = true;
      return nullptr;
    }
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
    {
        invalidInput = true;
        return nullptr;
    }
    if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1))
    {
      invalidInput = true;
      return nullptr;
    }
    return new cherkasov::Parallelogram(x1, y1, x2, y2, x3, y3);
  }
  else if (inputCommand == "DIAMOND")
  {
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double x3 = 0.0;
    double y3 = 0.0;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (!input || (x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3))
    {
      invalidInput = true;
      return nullptr;
    }
    return new cherkasov::Diamond(x1, y1, x2, y2, x3, y3);
  }
  invalidInput = true;
  return nullptr;
}

