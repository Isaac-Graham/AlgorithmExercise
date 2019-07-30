//
// Created by Isaac Graham on 7/30/2019.
//


/**
 * 没啥可以说的
 * 直接暴力就好了
 * 注意边界情况
 * 边界样例是main方法中的哪个
 * 这里用的是分治的思维
 * 其实没啥差别
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> table = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
    };

    vector<string> letterCombinations(string digits) {
        return letterCombinations(digits, 0, digits.length() - 1);
    }

    vector<string> letterCombinations(string digits, int begin, int end) {
        if (end >= begin) {
            if (end - begin == 1) {
                vector<string> concat_array;
                for (int i = 0; i < this->table[digits[begin] - 48].size(); i++) {
                    for (int j = 0; j < this->table[digits[end] - 48].size(); j++) {
                        concat_array.push_back(this->table[digits[begin] - 48][i] + this->table[digits[end] - 48][j]);
                    }
                }
                return concat_array;
            } else if (end - begin == 0) {
                return this->table[digits[begin] - 48];
            } else {
                int mid = (begin + end) / 2;
                vector<string> v1 = letterCombinations(digits, begin, mid);
                vector<string> v2 = letterCombinations(digits, mid + 1, end);
                vector<string> concat_array;
                for (int i = 0; i < v1.size(); i++) {
                    for (int j = 0; j < v2.size(); j++) {
                        concat_array.push_back(v1[i] + v2[j]);
                    }
                }
                return concat_array;
            }
        } else {
            return {};
        }
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> v = s->letterCombinations("");
    for (int index = 0; index < v.size(); index++) {
        cout << v[index] << " ";
    }
    cout << endl;
}