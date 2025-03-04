#include "diamond.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3)
  : vertex1{x1, y1},
    vertex2{x2, y2},
    vertex3{x3, y3},
    vertex4{x2 + (x1 - x3), y2 + (y3 - y1)},
    center{(x1 + x3) / 2, (y1 + y3) / 2}
    {
      if (((x1 == x2 && y1 == y2) && (x1 == x3 && y1 == y3)))
      {
        throw std::invalid_argument("no input coordinat diamond");
      }
    }
  double Diamond::getArea() const
  {
    double diag1 = vertex1.y - vertex3.y;
    double diag2 = vertex2.x - vertex4.x;
    return (diag1 * diag2) / 2;
  }
  rectangle_t Diamond::getFrameRect() const
  {
    double minX = std::min({ vertex1.x, vertex2.x, vertex3.x, vertex4.x });
    double maxX = std::max({ vertex1.x, vertex2.x, vertex3.x, vertex4.x });
    double minY = std::min({ vertex1.y, vertex2.y, vertex3.y, vertex4.y });
    double maxY = std::max({ vertex1.y, vertex2.y, vertex3.y, vertex4.y });
    rectangle_t rect{maxX - minX, maxY - minY, center};
    return rect;
  }
  void Diamond::move(point_t c)
  {
    double moveX = c.x - center.x;
    double moveY = c.y - center.y;
    moveVertex(vertex1, moveX, moveY);
    moveVertex(vertex2, moveX, moveY);
    moveVertex(vertex3, moveX, moveY);
    moveVertex(vertex4, moveX, moveY);
    center = c;
  }
  void Diamond::move(double dx, double dy)
  {
    move({center.x + dx, center.y + dy});
  }
  void Diamond::scale(double k)
  {
    if (k < 0)
    {
      throw std::invalid_argument("k must be positive");
    }
    scalePoint(vertex1, center, k);
    scalePoint(vertex2, center, k);
    scalePoint(vertex3, center, k);
    scalePoint(vertex4, center, k);
  }
}