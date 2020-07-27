//
// Created by Isc on 2020/7/26.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        if (target.empty()) { return 0; }
        string newString = '0' + target;
        int res = 0;
        for (int i = 1; i < newString.length(); i++) {
            if (newString[i] != newString[i - 1]) {
                res++;
            }
        }
        return res;
    }
};