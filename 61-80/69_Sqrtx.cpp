//
// Created by Isc on 2020/1/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)return 1;
        long long begin = 0;
        long long end = x;
        long long mid ;
        int res = 0;
        while (begin < end) {
            mid = (begin + end) / 2;
            long long  power = pow(mid, 2);
            if (power == x) {
                return mid;
            } else if (power < x) {
                res = mid;
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->mySqrt(2147395599) << endl;
//    for (int i = 0; i < 20; i++) {
//        cout << s->mySqrt(i) << endl;
//    }
}