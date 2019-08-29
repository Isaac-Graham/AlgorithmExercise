//
// Created by isc- on 2019/8/29.
//
#include <bits/stdc++.h>

class Solution {
public:
    double myPow(double x, int n) {
        long power = abs((long)n);
        double result = 1;
        while (power > 0) {
            for (long i = 1; power - i >= 0; power -= i, i *= 2) {
                result *= pow(x, i);
            }
        }

        return n > 0 ? result : 1 / result;
    }
};

int main() {
    Solution *s = new Solution();
    std::cout << s->myPow(1, -2147483648) << std::endl;
}

