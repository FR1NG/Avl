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

  try {
  avl.insert(pair(2, 42));
  avl.insert(pair(1, 13));
  avl.insert(pair(3, 1337));
  avl.insert(pair(4, 1337));
  avl.insert(pair(-1, 1337));
  avl.insert(pair(5, 1337));
    int i = avl.height(avl.getRoot());
    int factor = avl.getBalenceFactor(avl.getRoot());
    std::cout << "height is : " << i << std::endl;
    std::cout << "balence factor is : " << factor << std::endl;
  } catch (...) {

    std::cout << "exception has been catched" << std::endl;
    
  }
  return 0;
}
