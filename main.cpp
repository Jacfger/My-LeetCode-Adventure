#include "utils/Graph.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  Graph<int> x;

  std::cout << "add node" << std::endl;
  x.add_node(0, 1);
  std::cout << x << std::endl;
  std::cout << "remove node" << std::endl;
  x.remove_node_adjlist(1, 0);
  std::cout << x << std::endl;

  std::cout << "hello world" << std::endl;
}
