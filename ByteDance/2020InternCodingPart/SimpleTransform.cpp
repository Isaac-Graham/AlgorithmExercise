//
// Created by Isaac_Chen on 2020/4/12.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 0; loop < testcase; loop++) {
        int number = 0;
        cin >> number;
        vector<int> vec1;
        vector<int> vec2;
        for (int i = 0; i < number; i++) {
            int num = 0;
            cin >> num;
            vec1.push_back(num);
        }
        for (int i = 0; i < number; i++) {
            int num = 0;
            cin >> num;
            vec2.push_back(num);
        }

        bool left = false;
        bool right = false;
        int difference = 0;
        bool res = true;
        for (int i = 0; i < vec1.size(); i++) {
            if (!left) {
                if (vec1[i] == vec2[i]) {
                    continue;
                } else {
                    left = true;
                    difference = vec1[i] - vec2[i];
                }
            } else if (!right) {
                if (vec1[i] == vec2[i]) {
                    right = true;
                    continue;
                }
                if (vec1[i] - vec2[i] != difference) {
                    res = false;
                    break;
                }
            } else {
                if (vec1[i] != vec2[i]) {
                    res = false;
                    break;
                }
            }
        }
        // 曲线救国
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
