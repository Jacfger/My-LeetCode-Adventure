#include <vector>

#include "helper.h"
#ifndef __HELPER_H__
#define print(msg)
#endif

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_to_idx;
        auto wi = s.begin(), wj = s.begin();
        long max_length = 0;
        for (auto wj = s.begin(); wj != s.end(); ++wj) {
            auto it = char_to_idx.find(*wj);
            if (it != char_to_idx.end()) {
                wi = max(wi, s.begin() + char_to_idx[*wj] + 1);
            }
            max_length = max(max_length, wj - wi + 1);
            char_to_idx[*wj] = wj - s.begin();
            print(char_to_idx);
        }
        return max_length;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    print(solution.lengthOfLongestSubstring(s));
    s = "bbbbb";
    print(solution.lengthOfLongestSubstring(s));
    s = "pwwkew";
    print(solution.lengthOfLongestSubstring(s));
    s = "";
    print(solution.lengthOfLongestSubstring(s));
    s = " ";
    print(solution.lengthOfLongestSubstring(s));
    print(123);
    print(vector<int>({123, 456}));

    print<print_options{", ", "\n"}>(123, 456, vector<int>{123, 456, 789});
    // print(123, 456, vector<int>{123, 456, 789});
    return 0;
}