//
// Created by Isaac Graham on 8/2/2019.
//

/**
 * 用stack的思路
 * 先往stack里面预压-1，然后每次遇到(压栈，遇到)就pop，然后计算此时的index与栈顶的差，update一下就好
 * 注意这个-1有可能需要更新，如果这个样例")()())"，第一次遇到)的时候实际上是没用的，此时我栈内的-1应该更新成0
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string &s) {
        stack<int> stack1;
        stack1.push(-1);
        int longest_dis = 0;
        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '(')
                stack1.push(index);
            else {
                if (stack1.size() == 1) {
                    stack1.pop();
                    stack1.push(index);
                    continue;
                }
                stack1.pop();
                int dis = index - stack1.top();
                if (longest_dis < dis)
                    longest_dis = dis;
            }
        }
        return longest_dis;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->longestValidParentheses(")()())") << endl;
}