#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <utility>

template <class Key, class Value, class Type = std::pair<Key, Value>,
          class Compare = std::less<Key>,
          class Allocator = std::allocator<Type> >
class Avl {
public:
  typedef Type value_type;
  typedef value_type *pointer;
  typedef value_type &reference;
  typedef size_t size_type;
  // Node class [ begin ]
  class Node {
  private:
    Type *data_;
    Node *left_;
    Node *right_;
    Compare comparer_;

  public:
    typedef Type value_type;
    typedef value_type *pinter;
    typedef value_type &reference;
    Node() : data_(NULL), left_(NULL), right_(NULL), comparer_(Compare()) {}
    Node(const Type &data)
        : data_(new value_type(data)), left_(NULL), right_(NULL), comparer_(Compare()){}
    Node *getLeft() const { return this->left_; }
    Node *getRight() const { return this->right_; }
    void setLeft(Node *node) {
      std::cout << "left set has been called to set : " << node->getKey()
                << " left to: " << this->getKey() << std::endl;
      this->left_ = node;
    }
    void setRigh(Node *node) {
      std::cout << "right set has been called to set : " << node->getKey()
                << " right to: " << this->getKey() << std::endl;
      this->right_ = node;
    }
    Key getKey() const { return this->data_->first; }
    bool operator<(const Node &node) {
      return comparer_(this->getKey(), node.getKey());
    }
    bool operator==(const Node &node) {
      return (this->getKey() == node.getKey());
    }
    ~Node() { delete data_; }
  };
  // node class [ end ]

private:
  Node *root_;
  size_type size_;
  void recursive_insert_(Node *node, Node *parent) {
    if (*node == *parent ){
      throw std::runtime_error("duplicated key");
    } else if (*node < *parent) {
      if(parent->getLeft())
        recursive_insert_(node, parent->getLeft());
      else 
        parent->setLeft(node);
    } else {
      if (parent->getRight())
        recursive_insert_(node, parent->getRight());
      else
        parent->setRigh(node);
    }
  }

public:
  Avl() : root_(NULL), size_(0) {}
  Avl(const value_type data) : root_(new Node(data)), size_(1) {}
  size_type size() const { return this->size_; }
  Node *getRoot() const { return this->root_; }
  Node *insert(const value_type data) {
    Node *newNode = new Node(data);
    Node *root = this->root_;
    if (!root) {
      root_ = newNode;
      this->size_++;
      return newNode;
    }
    if (this->size() == 1) {
      if (*newNode < *root)
        root->setLeft(newNode);
      else if (*newNode == *root)
          throw std::runtime_error("duplicated key");
      else
        root->setRigh(newNode);
      this->size_++;
      return newNode;
    }
    this->recursive_insert_(newNode, root);
    this->size_++;
    return newNode;
  }
  int height(Node *node) {
    if(!node)
      return -1;
    int leftheight = height(node->getLeft());
    int rightheight = height(node->getRight());
    if(leftheight > rightheight)
      return leftheight + 1;
    return rightheight + 1;
  }
  int getBalenceFactor(Node* node)
{
    return (height(node->getLeft()), height(node->getRight()));
  }
};
