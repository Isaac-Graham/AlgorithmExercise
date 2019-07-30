//
// Created by Isaac Graham on 7/30/2019.
//

/**
 * 暴力就完事了
 * main里面是最开始没有考虑到的边界条件导致runtime_error
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> stack1;
        for (int index = 0; index < s.length(); index++) {
            if (s[index] == '(' || s[index] == '[' || s[index] == '{')
                stack1.push(s[index]);
            else {
                if (stack1.empty())
                    return false;
                if (s[index] == ')' && stack1.top() == '(')
                    stack1.pop();
                else if (s[index] == ']' && stack1.top() == '[')
                    stack1.pop();
                else if (s[index] == '}' && stack1.top() == '{')
                    stack1.pop();
                else
                    return false;
            }
        }
        if (stack1.empty())
            return true;
        else
            return false;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isValid("]");
}