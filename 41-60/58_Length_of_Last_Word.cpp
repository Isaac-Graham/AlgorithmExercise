//
// Created by Isaac_Chen on 2020/1/10.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const string &s) {
        int length = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (length == 0) {
                    continue;
                } else
                    return length;
            }
            length++;
        }
        return length;
    }
};

int main() {
    Solution *s = new Solution();
    string str = "s ";
    cout << s->lengthOfLastWord(str);
}