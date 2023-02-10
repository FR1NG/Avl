#include <string>

std::string repeat(std::string str, int n) {
  std::string tmp;
  for (int i = 0; i < n; i++)
    tmp += str;
  return tmp;
}
