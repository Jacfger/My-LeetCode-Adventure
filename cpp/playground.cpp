#include "helper.h"

// experiment with lower_bound, upper_bound

int main()
{
    vector<int> nums = {1, 2, 3, 3, 5, 5, 5, 6, 7, 8, 9};
    auto it = lower_bound(nums.begin(), nums.end(), 4);
    cout << it - nums.begin() << endl;
    it = upper_bound(nums.begin(), nums.end(), 5);
    cout << it - nums.begin() << endl;
    return 0;
}