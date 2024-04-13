#include "helper.h"
#ifndef __HELPER_H__
#define print(...)
#endif

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        print("sorted", nums);
        vector<vector<int>> threesums;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            print("3sum", *it, it - nums.begin());
            int offset = it - nums.begin() + 1;
            // auto two_sums = twoSum(
            //     span(nums.data() + offset, nums.size() - offset), -(*it));
            auto two_sums =
                twoSum(nums, it - nums.begin() + 1, nums.size() - 1, -*it);
            for (auto&& r : two_sums) {
                threesums.push_back({*it, r[0], r[1]});
            }
            for (; it != nums.end() - 1 && *it == *(it + 1); ++it)
                ;
        }
        return threesums;
    }
    vector<vector<int>> twoSum(const vector<int>& nums, int l, int r,
                               int target) {
        if (l >= r) return {};
        print(vector<int>{nums.begin() + l, nums.end()}, target);
        vector<vector<int>> results;
        // int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            print(l, r, sum);
            if (sum > target) {
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                };
                r--;
            } else if (sum < target) {
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                };
                l++;
            } else {
                results.push_back({nums[l], nums[r]});
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                };
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                };
                r--;
                l++;
            }
        }
        // if (results.size()) fmt::print("{} adds to {}.\n", results, target);
        return results;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, -2, -5, -5, -3, 2, -4};
    print(nums);
    vector<vector<int>> res = s.threeSum(nums);
    print(res, "three sums");

    return 0;
}