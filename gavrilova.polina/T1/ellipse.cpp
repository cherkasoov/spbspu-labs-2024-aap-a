#include "ellipse.hpp"
#include <iostream>
#include "base-types.hpp"
gavrilova::Ellipse::Ellipse(point_t center, double radiusX, double radiusY) :
  center_(center),
  radiusX_(radiusX),
  radiusY_(radiusY)
{
  if (radiusX <= 0 || radiusY <= 0) {
    throw std::logic_error("Invalid radiuses for ellipse");
  }
}

double gavrilova::Ellipse::getArea() const {
  return 3.14159 * radiusX_ * radiusY_;
}

gavrilova::rectangle_t gavrilova::Ellipse::getFrameRect() const {
  rectangle_t frameRect;
  frameRect.height = 2 * radiusY_;
  frameRect.width = 2 * radiusX_;
  frameRect.pos.x = center_.x;
  frameRect.pos.y = center_.y;
  return frameRect;
}

void gavrilova::Ellipse::move(point_t p) {
  center_.x = p.x;
  center_.y = p.y;
}

void gavrilova::Ellipse::move(double difX, double difY) {
  center_.x += difX;
  center_.y += difY;
}

void gavrilova::Ellipse::scale(double k) {
  radiusX_ *= k;
  radiusY_ *= k;
}
