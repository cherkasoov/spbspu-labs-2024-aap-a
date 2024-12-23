#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.hpp"

namespace cherkasov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
}
#endif
