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

  avl.insert(pair(5, 42));
  avl.insert(pair(3, 42));
  avl.insert(pair(7, 42));
  avl.insert(pair(1, 42));
  avl.insert(pair(4, 42));
  avl.insert(pair(6, 42));
  avl.insert(pair(9, 42));
  avl.insert(pair(8, 42));

  Node* toRotate = avl.getRoot()->getRight();

  // std::cout << toRotate->getKey() << std::endl;
  toRotate->RotateLeft();
  Node* root = avl.getRoot();

  std::cout << root->getRight()->getLeft()->getRight()->getKey() << std::endl;
  return 0;
}
