//
// Created by Isaac Graham on 7/20/2019.
//


/**
 * 暴力就完事了
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<char> roman_char = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string roman;
        for (int index = 6; index >= 0; index -= 2) {
            int zeros = (int) pow(10, index / 2);
            if (num / zeros == 0)
                continue;
            if (num / zeros <= 3) {
                while (num / zeros != 0) {
                    num -= zeros;
                    roman += roman_char[index];
                }
            } else if (num / zeros == 4) {
                num -= (4 * zeros);
                roman += roman_char[index];
                roman += roman_char[index + 1];
            } else if (num / zeros <= 8 && num / zeros >= 5) {
                num -= (5 * zeros);
                roman += roman_char[index + 1];
                while (num / zeros != 0) {
                    num -= zeros;
                    roman += roman_char[index];
                }
            } else {
                num -= (9 * zeros);
                roman += roman_char[index];
                roman += roman_char[index + 2];
            }
        }
        return roman;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->intToRoman(1986) << endl;
}