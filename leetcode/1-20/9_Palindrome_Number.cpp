//
// Created by isc- on 2019/8/29.
//

#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        std::string s = std::to_string(x) + "";
        for (int i = 0, j = s.size() - 1; j - i >= 1; j--, i++) {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    std::cout << s->isPalindrome(120) << std::endl;
}