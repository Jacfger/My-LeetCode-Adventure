#include "helper.h"

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp_l2_dist = [](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        make_heap(points.begin(), points.end(), cmp_l2_dist);
        while (points.size() > k) {
            pop_heap(points.begin(), points.end(), cmp_l2_dist);
            points.pop_back();
        }
        return points;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    _print(solution.kClosest(points, k));
    return 0;
}