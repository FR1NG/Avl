#pragma once
#include <functional>
#include <iostream>

template <class Type, class Comp> class Avl {
public:
  typedef Type value_type;
  typedef value_type *pointer;
  typedef value_type &reference;
  typedef Comp compare;
private:
  compare compare_;

  // Node class [ begin ]
  class Node {
  private:
    Type *data_;
    Node *left_;
    Node *right_;
    compare compare_;

  public:
    typedef Type value_type;
    typedef value_type *pinter;
    typedef value_type &reference;
    Node() : data_(NULL), left_(NULL), right_(NULL) {}
    Node(const Type& data)
        : data_(new value_type(data)), left_(NULL), right_(NULL) {}
    Node *getLeft() const { return this->left_; }
    Node *getRight() const { return this->right_; }
    void setLeft(const Node *node) { this->right_ = node; }
    void setRigh(const Node *node) { this->right_ = node; }
    pointer getData() const { return this->data_;}

    bool operator<(const Node &node) {
      return compare_(this->key(), node.key());
    }
    ~Node() { delete data_; }
  };
  // node class [ end ]

  private:
    Node* root_;

  public:
  Avl(): root_(NULL) {}
  Avl(const value_type data): root_(new Node(data)) {}
  Node* insert(const value_type data)
  {
   Node* head; 
    head = this->root_;
    while(head)
    {
        if (compare_(k))
      }
  }
};
