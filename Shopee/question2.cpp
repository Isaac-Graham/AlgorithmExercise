//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 两个字符串是否相等
     * @param str1 string字符串 第一个字符串
     * @param str2 string字符串 第二个字符串
     * @return bool布尔型
     */
    bool isStrsEqu(string str1, string str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        int length = str1.length();
        if (length % 2 == 1) {
            return str1 == str2;
        } else {
            int mid = length / 2;
            bool res1Con1 = isStrsEqu(str1.substr(0, mid), str2.substr(0, mid));
            bool res2Con1 = isStrsEqu(str1.substr(mid, length - mid), str2.substr(mid, length - mid));
            bool res1Con2 = isStrsEqu(str1.substr(0, mid), str2.substr(mid, length - mid));
            bool res2Con2 = isStrsEqu(str1.substr(mid, length - mid), str2.substr(0, mid));
            bool res = str1 == str2 || (res1Con1 && res2Con1) || (res1Con2 && res2Con2);
            return res;
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->isStrsEqu("aaba", "abaa") << endl;
    cout << solution->isStrsEqu("abab", "aabb") << endl;
}