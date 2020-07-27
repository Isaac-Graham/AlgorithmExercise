//
// Created by Isc on 2020/7/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int> &indices) {
        if (s.size() != indices.size()) { return ""; }
        if (s.empty()) { return ""; }
        for (int i = 0; i < s.size(); i++) {
            while (indices[i] != i) {
                char tmpChar = s[indices[i]];
                s[indices[i]] = s[i];
                s[i] = tmpChar;
                int tmpIndex = indices[indices[i]];
                indices[indices[i]] = indices[i];
                indices[i] = tmpIndex;
            }
        }
        return s;
    }
};

