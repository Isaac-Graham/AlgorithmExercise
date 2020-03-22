//
// Created by Isc on 2020/1/14.
//
#include <bits/stdc++.h>

using namespace std;

const int ZERO = 48;
const int ONE = 49;
const int TWO = 50;
const int THREE = 51;
const int FOUR = 52;
const int FIVE = 53;
const int SIX = 54;
const int SEVEN = 55;
const int EIGHT = 56;
const int NINE = 57;
const int PLUS = 43;
const int MINUS = 45;
const int DOT = 46;
const int E = 69;
enum State {
    START, SYMBOL, NUMBER, POINT, EXPONENT
};

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;

        // skip the whilespaces
        for (; s[i] == ' '; i++) {}

        // check the significand
        if (s[i] == '+' || s[i] == '-') i++; // skip the sign if exist

        int n_nm, n_pt;
        for (n_nm = 0, n_pt = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; i++)
            s[i] == '.' ? n_pt++ : n_nm++;
        if (n_pt > 1 || n_nm < 1) // no more than one point, at least one digit
            return false;

        // check the exponent if exist
        if (s[i] == 'e') {
            i++;
            if (s[i] == '+' || s[i] == '-') i++; // skip the sign

            int n_nm = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++, n_nm++) {}
            if (n_nm < 1)
                return false;
        }

        // skip the trailing whitespaces
        for (; s[i] == ' '; i++) {}

        return s[i] == 0;  // must reach the ending 0 of the string
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isNumber("    +9       ");
}