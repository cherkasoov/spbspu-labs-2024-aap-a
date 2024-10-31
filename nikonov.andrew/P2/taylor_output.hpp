#ifndef TAYLOR_OUTPUT_HPP
#define TAYLOR_OUTPUT_HPP
#include <stdexcept>
#include <cstddef>
namespace nikonov
{
  void stringOutput(double x, double val, double stdval);
  void stringOutput(double x, const std::logic_error& e, double stdval);
}
#endif
