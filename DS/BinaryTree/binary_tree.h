#include <iostream>
#include <memory>

class Node {
public:
  Node() = default;
  ~Node() = default;
  std::unique_ptr<Node> parent, left, right;
};

class BinaryTree {
public:
  BinaryTree() : rootNode(std::make_unique<Node>()){};

private:
  std::unique_ptr<Node> rootNode;
};
