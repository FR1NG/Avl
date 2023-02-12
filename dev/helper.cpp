#include "helper.hpp"

namespace ft {
std::string repeat(std::string str, int n) {
  std::string tmp;
  for (int i = 0; i < n; i++)
    tmp += str;
  return tmp;
}
} // namespace ft
