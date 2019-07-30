//
// Created by Isaac Graham on 7/20/2019.
//


// 分治就完事了
// 先求出左右两半部分的最长前缀
// 然后一起合起来求就可以
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

    string longestCommonPrefix(vector<string> &strs, int begin, int end) {
        if (end - begin < 0) {
            return "";
        } else {
//        cout << 1 << endl;
            if (end - begin == 1) {
//            cout << 2 << endl;
                for (int index = 0; index < min(strs[begin].length(), strs[end].length()); index++) {
                    if (strs[begin][index] != strs[end][index])
                        return strs[begin].substr(0, index);
                }
                cout << strs[begin].substr(0, min(strs[begin].length(), strs[end].length())) << endl;
                return strs[begin].substr(0, min(strs[begin].length(), strs[end].length()));
            } else if (end - begin == 0) {
//            cout << 3 << endl;
                return strs[begin];
            } else {
//            cout << 4 << endl;
                int mid = (begin + end) / 2;
                string str1 = longestCommonPrefix(strs, begin, mid);
                string str2 = longestCommonPrefix(strs, mid + 1, end);


                // conquer
                for (int index = 0; index < min(str1.length(), str2.length()); index++) {
                    if (str1[index] != str2[index]) {
                        return str1.substr(0, index);
                    }
                }
                return str1.substr(0, min(str1.length(), str2.length()));
            }
        }
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution *s = new Solution();
    cout << s->longestCommonPrefix(strs, 0, strs.size() - 1) << endl;
}