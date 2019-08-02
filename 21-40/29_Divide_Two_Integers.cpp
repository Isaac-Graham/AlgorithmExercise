//
// Created by Isaac Graham on 8/2/2019.
//

/**
 * 用dividend减去divisor
 * 每次减完divisor倍增
 * 时间复杂度大概是logn
 * 这道题难在边界条件不好控制
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(long dividend, long divisor) {
        bool same_sign = (divisor > 0 && dividend > 0) || (dividend < 0 && divisor < 0);
        divisor = abs(divisor);
        dividend = abs(dividend);
        long quotient = 0;
        while (dividend >= divisor) {
            for (long times = 1; dividend >= times * divisor; times *= 2) {
                dividend -= divisor * times;
                if (INT_MIN >= -1 * quotient - times)
                    return same_sign ? INT_MAX : INT_MIN;
                quotient += times;
            }
        }
        return (same_sign ? quotient : -1 * quotient);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->divide(2147483648, -1);
}