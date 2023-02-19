#include "helpers.hpp"
#include <cmath>

namespace ft {
std::string repeat(std::string str, int n)
{
  std::string buffer;
  for(int i = 0; i < n; i++)
    buffer+=str;
  return buffer;
}
void printEdges(int height, int level, int maxHeight){
  for (int i = 0; i < height; i++) {
       std::cout << repeat(" ", (maxHeight - level) * height);
    for(int x = 0; x < level; x++)
      std::cout <<  repeat(" ", height - i) << "/" << ft::repeat(" ", i * 2) << "\\" << repeat(" ", height - i);
    std::cout << std::endl;
  }
}
} // namespace ft
