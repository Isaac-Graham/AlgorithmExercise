//
// Created by Isc on 2020/8/26.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 获取满足条件的最长子串的长度
     * @param str string字符串 输入的字符串
     * @return int整型
     */
    int getMaxSubstringLen(string str) {
        int ans = 0;
        int status = 0;
        int length = str.size();
        vector<int> position(1 << 5, -1);
        position[0] = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == 'a') {
                status ^= 1 << 0;
            } else if (str[i] == 'b') {
                status ^= 1 << 1;
            } else if (str[i] == 'c') {
                status ^= 1 << 2;
            } else if (str[i] == 'd') {
                status ^= 1 << 3;
            } else if (str[i] == 'e') {
                status ^= 1 << 4;
            }
            if (~position[status]) {
                ans = max(ans, i + 1 - position[status]);
            } else {
                position[status] = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->getMaxSubstringLen("aabbffced") << endl;
    cout << solution->getMaxSubstringLen("asdfajskfbb") << endl;
}