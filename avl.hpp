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
    Node *parent_;
    Compare comparer_;


  public:
    typedef Type value_type;
    typedef value_type *pinter;
    typedef value_type &reference;

    Node()
        : data_(NULL), left_(NULL), right_(NULL), parent_(NULL),
          comparer_(Compare()) {}

    Node(const Type &data)
        : data_(new value_type(data)), left_(NULL), right_(NULL), parent_(NULL),
          comparer_(Compare()) {}

    pointer data() { return this->data_; }

    Node *getLeft() const { return this->left_; }

    Node *getRight() const { return this->right_; }

    Node *getParent() const { return this->parent_; }

    void setLeft(Node *node) {
      this->left_ = node;
      if (node)
        node->setParent(this);
    }

    void setRight(Node *node) {
      this->right_ = node;
      if (node)
        node->setParent(this);
    }

    void setParent(Node *node) { this->parent_ = node; }

    Key getKey() const {
      if (!data_)
        throw std::runtime_error("trying to get key of null node");
      return this->data_->first;
    }

    Value getValue() const {
      if (!data_)
        throw std::runtime_error("trying to get value of null node");
      return this->data_->second;
    }

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
    if (*node == *parent) {
      throw std::runtime_error("duplicated key");
    } else if (*node < *parent) {
      if (parent->getLeft())
        recursive_insert_(node, parent->getLeft());
      else
        parent->setLeft(node);
    } else {
      if (parent->getRight())
        recursive_insert_(node, parent->getRight());
      else
        parent->setRight(node);
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
        root->setRight(newNode);
      this->size_++;
      return newNode;
    }
    this->recursive_insert_(newNode, root);
    this->size_++;
    return newNode;
  }
  int height(Node *node) {
    if (!node)
      return -1;
    int leftheight = height(node->getLeft());
    int rightheight = height(node->getRight());
    if (leftheight > rightheight)
      return leftheight + 1;
    return rightheight + 1;
  }
  int getBalenceFactor(Node *node) {
    return (height(node->getLeft()), height(node->getRight()));
  }

  void setRoot(Node *node) { this->root_ = node; }

  Node *rotateLeft(Node* node) {
    // ! dont forget to handle if the parent is null;
    // getting the parent and the right child
    Node *child = node->getRight();
    Node *parent = node->getParent();

    // assinging the child to his el grande padre to become his padre
    if (parent) {
      node == parent->getRight() ? parent->setRight(child)
                                 : parent->setLeft(child);
    }

    if (child)
      node->setRight(child->getLeft());
    if (child)
      child->setLeft(node);
    node->setParent(child);
    if (child)
      child->setParent(parent);
    if (child && !child->getParent())
      node->setRoot(child);
    return node;
  }

  Node *rotateRight(Node *node) {
    Node *child = node->getLeft();
    Node *parent = node->getParent();

    // std::cout<< "here " << std::endl;
    node->setLeft(child ? child->getRight() : NULL);
    if (child)
      child->setParent(parent);
    if (parent) {
      node == parent->getRight() ? parent->setRight(child)
                                 : parent->setLeft(child);
    }
    if (child)
      child->setRight(node);
    node->setParent(child);
    if (child && !child->getParent())
      this->setRoot(child);
    return node;
  }
};
