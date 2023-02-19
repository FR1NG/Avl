#include "avl.hpp"
#include "dev/helpers.hpp"
#include "dev/print_tree.hpp"
#include <functional>
#include <ios>
#include <iostream>
#include <utility>
#include <memory>

typedef std::pair<int, int> pair;
typedef std::allocator<pair> allocator;
typedef Avl<int, int>::Node Node;
// typedef typename std::less<int> comp;


// void testBalence(Node* node)
// {
//   Node* head;
//   head = node;
// int factor = 0;
//   while(head)
//     {
//       factor = Avl<int, int>::getBalenceFactor(head);
//       if (factor > 1 || factor < -1)
//       {
//         std::cout << "tree unbalenced" << std::endl;
//         return;
//       }
//       head = head->getParent();
//     }
//   std::cout << "tree is balenced" << std::endl;
// }

int main ()
{
  Avl<int, int> avl;

  avl.insert(pair(100, 42));
  avl.insert(pair(75, 42));
  avl.insert(pair(70, 42));

  // std::cout << avl.height(avl.getRoot()) << std::endl;

  std::cout << avl.getRoot()->getKey() << std::endl;
  std::cout << avl.getRoot()->getLeft()->getKey() << std::endl;
  std::cout << avl.getRoot()->getRight()->getKey() << std::endl;
  return 0;
}
