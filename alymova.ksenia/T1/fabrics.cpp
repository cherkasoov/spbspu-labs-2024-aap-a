#include "fabrics.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
/*alymova::Shape* alymova::Creator::create(std::string name, std::istream& in)
{
  if (name == "RECTANGLE")
  {
    return createRectangle(in);
  }
  else if (name == "CIRCLE")
  {
    return createCircle(in);
  }
  else if (name == "REGULAR")
  {
    return createRegular(in);
  }
  return nullptr;
}*/
alymova::Shape* alymova::CreatorRectangle::create(std::istream& in)
{
  const size_t cnt_params = 4;
  double params[cnt_params] = {};
  Rectangle* shape = nullptr;
  readParameters(in, params, cnt_params);
  shape = new Rectangle(point_t{params[0], params[1]}, point_t{params[2], params[3]});
  return shape;
}
alymova::Shape* alymova::CreatorCircle::create(std::istream& in)
{
  const size_t cnt_params = 3;
  double params[cnt_params] = {};
  Circle* shape = nullptr;
  readParameters(in, params, cnt_params);
  shape = new Circle(point_t{params[0], params[1]}, params[2]);
  return shape;
}
alymova::Shape* alymova::CreatorRegular::create(std::istream& in)
{
  const size_t cnt_params = 6;
  double params[cnt_params] = {};
  Regular* shape = nullptr;
  readParameters(in, params, cnt_params);
  shape = new Regular(point_t{params[0], params[1]}, point_t{params[2], params[3]}, point_t{params[4], params[5]});
  return shape;
}
void alymova::readParameters(std::istream& in, double* params, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (!(in >> params[i]))
    {
      throw std::logic_error("Input shape parameters error");
    }
  }
}
