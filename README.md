# Avl
This is a templated AVL (Adelson-Velsky and Landis) Tree class implementation in C++. An AVL tree is a self-balancing binary search tree in which the height difference between the left and right subtree is no more than 1.

## Features
- Supports inserting key-value pairs as nodes
- Throws an error if the same key is tried to be inserted again
- Supports getting the height of a node
- Supports getting the balance factor of a node
- Supports rotating left and right

## Typedefs
The following type definitions are available for the users of this class:

- value_type: the data type for the node of the AVL tree
- pointer: a pointer to the node's data type
- reference: a reference to the node's data type
- size_type: an unsigned integer to represent the size of the tree
## Class Node
The AVL tree uses the Node class as its nodes. Each node has the following properties and methods:

- data_: a pointer to the node's data (value_type)
- left_: a pointer to the node's left child
- right_: a pointer to the node's right child
- parent_: a pointer to the node's parent
- comparer_: a comparison function object to compare the keys of the nodes (defaults to std::less<Key>)
- data(): returns the pointer to the node's data
- getLeft(): returns a pointer to the node's left child
- getRight(): returns a pointer to the node's right child
- getParent(): returns a pointer to the node's parent
- setLeft(Node *node): sets the left child of the node
- setRight(Node *node): sets the right child of the node
- setParent(Node *node): sets the parent of the node
- getKey(): returns the key of the node's data
- getValue(): returns the value of the node's data
- operator<: compares the keys of the nodes
- operator==: checks equality of the keys of the nodes
## Class Avl
The AVL tree is created using the Avl class. The following are its properties and methods:

- root_: a pointer to the root node of the tree
- size_: the size of the tree
- recursive_insert_(Node *node, Node *parent): a helper function to insert nodes into the tree recursively
- size(): returns the size of the tree
- getRoot(): returns a pointer to the root node of the tree
- insert(const value_type data): inserts a node with the given data into the tree
- height(Node *node): returns the height of the given node
- getBalenceFactor(Node *node): returns the balance factor of the given node
- setRoot(Node *node): sets the root node of the tree
- rotateLeft(Node *node): rotates the given node to the left
- rotateRight(Node *node): rotates the given node to the right
## Example Usage:
```c++
int main() {
  Avl<int, int> tree;
  tree.insert(std::make_pair(10, 10));
  tree.insert(std::make_pair(20, 20));
  tree.insert(std::make_pair(30, 30));
  tree.insert(std::make_pair(40, 40));
  tree.insert(std::make_pair(50, 50));
  tree.insert(std::make_pair(25, 25));
  std::cout << "The size of tree is: " << tree.size() << std::endl;
  std::cout << "key of the root node: " << tree.getRoot()->getKey() << std::endl;
  std::cout << "Value of the root node: " << tree.getRoot()->getKey() << std::endl;
  return 0;
}

```
