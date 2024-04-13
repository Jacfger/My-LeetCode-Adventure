#include "helper.h"
#ifndef __HELPER_H__
#define print(...)
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
    friend std::ostream &operator<<(std::ostream &os, const TreeNode &d) {
        return os << d.val;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        auto node_by_levels = deque<deque<TreeNode *>>{{root}};
        vector<vector<int>> nodes_val;
        while (!node_by_levels.empty()) {
            print(nodes_val);
            deque<TreeNode *> node_in_levels = node_by_levels.front(),
                              node_in_curr_level;
            node_by_levels.pop_front();
            vector<int> node_in_curr_level_val;
            while (!node_in_levels.empty()) {
                auto node = node_in_levels.front();
                node_in_levels.pop_front();
                if (node) {
                    node_in_curr_level.push_back(node->left);
                    node_in_curr_level.push_back(node->right);
                    node_in_curr_level_val.push_back(node->val);
                }
            }
            if (!node_in_curr_level.empty())
                node_by_levels.push_back(node_in_curr_level);
            if (!node_in_curr_level_val.empty())
                nodes_val.push_back(node_in_curr_level_val);
        }
        return nodes_val;
    }
};

int main() {
    Solution solution;

    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    vector<TreeNode *> tree_nodes;
    TreeNode *root = new TreeNode(nodes[0]);
    tree_nodes.push_back(root);
    for (int i = 1; i < nodes.size(); i++) {
        tree_nodes.push_back(new TreeNode(nodes[i]));
        // print("Curr node:", nodes[i],
        //       "Parent Node:", tree_nodes[(i - 1) / 2]->val);
        if (i % 2) {
            tree_nodes[(i - 1) / 2]->left =
                tree_nodes[i]->val != -1 ? tree_nodes[i] : nullptr;
        } else {
            tree_nodes[(i - 1) / 2]->right =
                tree_nodes[i]->val != -1 ? tree_nodes[i] : nullptr;
        }
    }
    // print(*root);
    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    print(solution.levelOrder(root));
    return 0;
}
