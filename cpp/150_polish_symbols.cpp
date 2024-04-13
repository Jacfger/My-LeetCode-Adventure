#include "helper.h"

#ifndef __HELPER_H__
#define print(...)
#endif

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stacks;
        for (auto&& t : tokens) {
            print(t);
            if (t == "+") {
                int a = stacks.top();
                stacks.pop();
                int b = stacks.top();
                stacks.pop();
                stacks.push(a + b);
            } else if (t == "-") {
                int a = stacks.top();
                stacks.pop();
                int b = stacks.top();
                stacks.pop();
                stacks.push(a - b);
            } else if (t == "*") {
                int a = stacks.top();
                stacks.pop();
                int b = stacks.top();
                stacks.pop();
                stacks.push(a * b);
            } else if (t == "/") {
                int a = stacks.top();
                stacks.pop();
                int b = stacks.top();
                stacks.pop();
                stacks.push(b / a);
            } else {
                stacks.push(stoi(t));
            }
            // should be all number
        }
        return stacks.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    print(solution.evalRPN(tokens));
}