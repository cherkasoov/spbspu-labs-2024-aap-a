#include <iostream>
#include "dynamicstrings.h"

int main()
{
  char * line = nullptr;
  line = savintsev::inputEndlessStr(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Failure to allocate memory\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    std::cerr << "No characters to convert\n";
    delete[] line;
    return 1;
  }
  std::cout << savintsev::getNumIdenticalInRow(line) << '\n';
  delete[] line;
}
