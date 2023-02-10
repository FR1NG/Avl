#pragma once
#include <iostream>
#include <sys/_types/_size_t.h>
#include <utility>

template <class Key, class Value, class Type = std::pair<Key, Value>, class Compare = std::less<Key>,
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

  public:
    typedef Type value_type;
    typedef value_type *pinter;
    typedef value_type &reference;
    Node() : data_(NULL), left_(NULL), right_(NULL) {}
    Node(const Type& data)
        : data_(new value_type(data)), left_(NULL), right_(NULL) {}
    Node *getLeft() const { return this->left_; }
    Node *getRight() const { return this->right_; }
    void setLeft(Node *node) { 
      std::cout << "leftset has been called to set : " << node->getKey() << "left to: " << this->getKey() << std::endl;
      this->left_ = node; }
    void setRigh(Node *node) { 
      std::cout << "rightset has been called to set : " << node->getKey() << "right to: " << this->getKey() << std::endl;
      this->right_ = node; }
    Key getKey() const { return this->data_->first; }
    bool operator<(const Node &node) {
      return Compare(this->getKey(), node.getKey());
    }
    ~Node() { delete data_; }
  };
  // node class [ end ]

  private:
    Node* root_;
    size_type size_;
    

  public:
  Avl(): root_(NULL), size_(0) {}
  Avl(const value_type data): root_(new Node(data)), size_(1) {}
  size_type size() const {return this->size_;}
  Node* getRoot() const {return this->root_;}
  Node *insert(const value_type data) {
    Node *newNode = new Node(data);
    Node *head = this->root_;
    if (!head) {
      root_ = newNode;
      this->size_++;
      return newNode;
    }
    if (this->size() == 1) {
      if (head > newNode)
        head->setLeft(newNode);
      else
        head->setRigh(newNode);
      this->size_++;
      return newNode;
    }
    while (head->getLeft() || head->getRight()) {
      if (head < newNode) {
        if (head->getLeft())
          head = head->getLeft();
        else {
          head->setLeft(newNode);
          break;
        }
      } else {
        if (head->getRight())
          head = head->getRight();
        else {
          head->setRigh(newNode);
          break;
        }
      }
    }
    this->size_++;
    return newNode;
  }
};
