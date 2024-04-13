#include "helper.h"
// #define _print(...)
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        queue<pair<int, int>> bfs_q;
        for (int j = 0; j < mat.size(); ++j) {
            for (int i = 0; i < mat[j].size(); ++i) {
                if (mat[j][i] == 0) {
                    bfs_q.push({j, i});
                } else {
                    mat[j][i] = -1;
                }
            }
        }
        while (!bfs_q.empty()) {
            auto [j, i] = bfs_q.front();
            bfs_q.pop();
            vector<pair<int, int>> offsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto& offset: offsets) {
                int new_j = j + offset.first;
                int new_i = i + offset.second;
                if (new_j < 0 || new_j >= mat.size() || new_i < 0 || new_i >= mat[j].size() || mat[new_j][new_i] != -1) {
                    continue;
                }
                mat[new_j][new_i] = mat[j][i] + 1;
                bfs_q.push({new_j, new_i});
            }
        }
        return mat;
    }
};

int main() {
    Solution solution;
    // vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 1, 1}, {1, 1, 0}};
    // vector<vector<int>> matrix = {{0}, {0}, {0}, {0}, {0}};
    _print(matrix);
    _print(solution.updateMatrix(matrix));
    return 0;
}
