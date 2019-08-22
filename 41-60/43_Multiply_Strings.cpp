//
// Created by Isaac Graham on 2019/8/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(const string &num1, const string &num2) {
        string str(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int tmp = c_to_i(str[i + j + 1]) + c_to_i(num1[i]) * c_to_i(num2[j]);
                str[i + j + 1] = (tmp % 10) + '0';
                str[i + j] += tmp / 10;
            }
        }

        for (int index = 0; index < str.size(); index++) {
            if (str[index] != '0')
                return str.substr(index);
        }
        return "0";

    }

    inline int c_to_i(char c) {
        return (int) c - 48;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->multiply("123", "456") << endl;
}