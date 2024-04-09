#include <iostream>
#include <vector>
#include "helper.h"
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> nums2;
        nums2.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            nums2.push_back(nums[i] + nums2[i - 1]);
        }
        int mnum = 100000;
        int s = 0;
        int maxsum = nums[0];
        for (int i = 0; i < nums2.size(); ++i)
        {
            maxsum = max(maxsum, nums2[i] - mnum);
            if (nums2[i] < mnum)
            {
                mnum = nums2[i];
                s = i;
            }
        }
        return max(maxsum, *max_element(nums2.begin(), nums2.end()));
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, -1};
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}