#pragma once

#include <iostream>
#include <sys/_types/_size_t.h>
#include "../avl.hpp"

namespace ft {


std::string repeat(std::string str, int n);

template<class Type>
void print_tree(Type tree)
{
  size_t level = 1;
  typedef typename Type::Node** nodes;
  nodes pairs;

  while (true) {
    pairs = new nodes[level];

    level++;
  }
}

}
