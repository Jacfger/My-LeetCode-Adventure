#include <algorithm>
#include <assert.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>

template <typename T> class Graph {
public:
  std::map<T, std::list<T>> adj_list;
  Graph(bool directed = false) : isDirected(false) {}
  void add_node(T a, T b) {
    adj_list[a].push_back(b);
    if (!isDirected) {
      adj_list[b].push_back(a);
    }
  }

  bool exist(T n) { return adj_list.find(n) != adj_list.end(); }

  void remove_node_adjlist(T a, T b) {
    if (!exist(b))
      return;
    for (auto &&node : adj_list[b]) {
      auto remove_ =
          std::remove(adj_list[node].begin(), adj_list[node].end(), b);
      assert(remove_ != adj_list[node].end());
      adj_list[node].erase(remove_);
      if (!adj_list[node].size()) {
        adj_list.erase(node);
      }
    }
    adj_list.erase(b);
  }

  friend std::ostream &operator<<(std::ostream &output, const Graph &g) {
    for (auto &&adj : g.adj_list) {
      output << adj.first << ":\n\t";
      for (auto &&node : adj.second) {
        output << node << ' ' << std::endl;
      }
      output << "\n";
    }
    return output;
  }

protected:
  bool isDirected;
};
