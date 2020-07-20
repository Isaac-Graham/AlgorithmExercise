
// Created by Isc on 2020/7/21.
//

#include <bits/stdc++.h>

using namespace std;

int solution(int x) {
    unsigned int xorValue = 0xffffffff ^x;
    int zeroNumber = 0;
    for (int i = 0; i < 32; i++) {
        if (xorValue % 2 == 0) {
            zeroNumber++;
        }
        xorValue = xorValue >> 1;
    }
    return pow(2, zeroNumber);
}

int duipai(int x) {
    long long ans = x == (1 << 31) - 1 ? 1ll: 2ll;
    for(; x; x -= -x & x) ans <<= 1;
    return ans;
}

int main() {
    int x = 0;
    cin >> x;
    cout << duipai(x) << endl;
    cout << solution(x) << endl;
}
