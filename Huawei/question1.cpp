//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;
const unsigned int MAX = pow(2, 31);

unsigned int change(unsigned int value) {
    unsigned int res = 0;
    for (int i = 0; i < 16; i++) {
        int highBit = value / MAX;
        value = value << 1;
        int lowBit = value / MAX;
        value = value << 1;
        res = (res * 2 + lowBit) * 2 + highBit;
    }
    return res;
}

int main() {
    unsigned int value;
    vector<unsigned int> vec;
    while (cin >> value) {
        vec.push_back(value);
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = change(vec[i]);
    }
    int highBit = 0;
    int lowBit = 0;
    for (int i = 0; i < vec.size(); i++) {
        unsigned int addSum = highBit * 0x80000000 + lowBit * 0x40000000;
        if ((vec[i] & 0x00000002) > 0) {
            highBit = 1;
        } else {
            highBit = 0;
        }
        if ((vec[i] & 0x00000001) > 0) {
            lowBit = 1;
        } else {
            lowBit = 0;
        }
        vec[i] = vec[i] >> 2;
        vec[i] += addSum;
    }
    unsigned int addSum = highBit * 0x80000000 + lowBit * 0x40000000;
    vec[0] += addSum;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}
