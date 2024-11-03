#include "stream.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

namespace balashov
{
  std::istream & inputMatrix(std::istream & in, int * matrix, size_t column, size_t row, size_t & read)
  {
    size_t count = row * column;
    for(size_t i =0; i < count; ++i)
    {
      if(!(in >> matrix[i]))
      {
        ++read;
      }
    }
    return in;
  }

  void outputMtx(std::ostream & out, const int * matrix, size_t column, size_t row)
  {
    out << column << " " << row;
    out << std::fixed;
    out << std::setprecision(1);
    for (size_t i = 0; i < column * row; ++i)
    {
      out << " " << matrix[i];
    }
  }
}
