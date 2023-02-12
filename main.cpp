#include "avl.hpp"
#include "dev/helper.hpp"
#include <functional>
#include <ios>
#include <iostream>
#include <utility>
#include <memory>

typedef std::pair<int, int> pair;
typedef std::allocator<pair> allocator;
typedef Avl<int, int>::Node Node;
// typedef typename std::less<int> comp;


int main ()
{
  Avl<int, int> avl;

  avl.insert(pair(100, 42));
  avl.insert(pair(200, 42));
  avl.insert(pair(80, 42));
  avl.insert(pair(95, 42));

  Node* toRotate = avl.getRoot()->getLeft();
  avl.rotateLeftRight(toRotate);
  std::cout << avl.getRoot()->getKey() << std::endl;
  // std::cout << avl.getRoot()->getRight()->getKey() << std::endl;

  return 0;
}
