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
  avl.insert(pair(70, 42));
  avl.insert(pair(200, 42));
  avl.insert(pair(30, 42));
  avl.insert(pair(80, 42));
  avl.insert(pair(150, 42));
  avl.insert(pair(270, 42));
  avl.insert(pair(25, 42));
  avl.insert(pair(57, 42));
  avl.insert(pair(78, 42));
  avl.insert(pair(95, 42));

  Node* toRotate = avl.getRoot();

  // std::cout << toRotate->getKey() << std::endl;
  // toRotate->rotateRight();
  avl.rotateRight(toRotate);
  Node* root = avl.getRoot();

  // std::cout << root->getLeft()->getRight()->getKey() << std::endl;
  std::cout << root->getRight()->getKey() << std::endl;
  return 0;
}
