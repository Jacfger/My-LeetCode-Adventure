#include "helper.h"

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        auto start_it =
            lower_bound(intervals.begin(), intervals.end(), newInterval[0],
                        [](vector<int>& a, int b) { return a[1] < b; });
        cout << start_it - intervals.begin() << endl;
        auto end_it =
            upper_bound(intervals.begin(), intervals.end(), newInterval[1],
                        [](int a, vector<int>& b) { return a < b[0]; });
        end_it--;
        cout << end_it - intervals.begin() << endl;

        if (start_it > end_it) {
            intervals.insert(start_it, newInterval);
        } else if (start_it <= end_it) {
            (*start_it)[0] = min((*start_it)[0], newInterval[0]);
            (*start_it)[1] = max((*end_it)[1], newInterval[1]);
            if (start_it < end_it) {
                intervals.erase(start_it + 1, end_it + 1);
            }
        }
        return intervals;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {3, 7};
    _print(intervals);
    _print(newInterval);
    _print(solution.insert(intervals, newInterval));
    return 0;
}