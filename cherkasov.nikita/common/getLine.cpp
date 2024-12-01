#include "getLine.h"
#include <iostream>
#include <cstring>
#include <istream>

char* cherkasov::inputLine(std::istream& in)
{
  size_t capacity = 13;
  size_t length = 0;
  char* buffer = new (std::nothrow) char[capacity]();
  if (!buffer)
  {
    std::cerr << "Error: Faile to allocate memory.\n";
    return nullptr;
  }
  char ch;
  std::noskipws(in);
  while (in.get(ch) && ch != '\n')
  {
    if (length + 1 >= capacity)
    {
      size_t newCapacity = capacity * 2;
      char* newBuffer = cherkasov::newArray(buffer, newCapacity);
      if (!newBuffer)
      {
        delete[] buffer;
        return nullptr;
      }
     buffer = newBuffer;
     capacity = newCapacity;
    }
    buffer[length++] = ch;
  }
  if (length == 0 && !in.eof())
  {
    std::cerr << "Error: Empty input.\n";
    delete[] buffer;
    return nullptr;
  }
  buffer[length] = '\0';
  return buffer;
}

char* cherkasov::newArray(char* oldArray, size_t newCapacity)
{
  char* newArray = new (std::nothrow) char[newCapacity];
  if (!newArray)
  {
    delete[] oldArray;
    std::cerr << "Error: Fail to allocate memory.\n";
    return nullptr;
  }
  if (oldArray)
  {
    size_t oldLength = (oldArray[0] != '\0') ? std::strlen(oldArray) : 0;
    std::strncpy(newArray, oldArray, oldLength);
    newArray[oldLength] = '\0';
  }
  delete[] oldArray;
  return newArray;
}