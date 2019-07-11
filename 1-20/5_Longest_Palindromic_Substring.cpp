//
// Created by Isaac Graham on 7/9/2019.
//
#include <bits/stdc++.h>

using namespace std;


// 本题思路：动态规划
//
class Solution {
public:
    string longestPalindrome(const string &s) {
        if (s.size() == 0)
            return "";
        int beg = 0, en = 0;
        vector<vector<int>> dp_array;
        for (int index = 0; index < s.size(); index++) {
            vector<int> v(s.size());
            dp_array.push_back(v);
        }
        for (int index = 0; index < s.size(); index++) {
            dp_array[index][index] = 1;
        }
        for (int begin = 0; begin < s.size() - 1; begin++) {
            int end = begin + 1;
            if (s[begin] == s[end]) {
                dp_array[begin][end] = 1;
                if (end - begin > en - beg) {
                    beg = begin;
                    en = end;
                }
            }
        }
        for (int difference = 1; difference < s.size(); difference++) {
            for (int begin = 0; begin < s.size(); begin++) {
                int end = begin + difference;
                if (end >= s.size())
                    continue;
                if (dp_array[begin + 1][end - 1] && s[begin] == s[end]) {
                    dp_array[begin][end] = 1;
                    if (difference > en - beg) {
//                        cout << "   " << difference << " " << begin << " " << beg << " " << end << " " << en
//                             << endl;
                        beg = begin;
                        en = end;
                    }
                }
            }
        }
//        for (int i = 0; i < s.size(); i++) {
//            for (int j = 0; j < s.size(); j++) {
//                cout << dp_array[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << beg << " " << en << endl;
        return s.substr(beg, en - beg + 1);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->longestPalindrome("") << 12 << endl;
}