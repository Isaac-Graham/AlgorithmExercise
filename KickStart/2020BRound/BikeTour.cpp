//
// Created by Isaac_Chen on 2020/4/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 1; loop <= testcase; loop++) {
        vector<int> vec;
        int checkout = 0;
        cin >> checkout;
        for (int i = 0; i < checkout; i++) {
            int input = 0;
            cin >> input;
            vec.push_back(input);
        }
        int sum = 0;
        for (int i = 1; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) {
                sum++;
            }
        }
        cout << "Case #" << loop << ": " << sum << "\n";
    }
}
