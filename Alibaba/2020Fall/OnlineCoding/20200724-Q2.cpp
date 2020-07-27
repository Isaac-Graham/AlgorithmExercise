//
// Created by Isc on 2020/7/24.
//

// 没做出来
// A 20/100
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 0; loop < testcase; ++loop) {
        int n, l;
        cin >> n >> l;
        vector<vector<int>> vec(n, vector<int>(l, 0));
        for (int i = 0; i < n; i++) {
            string row = "";
            cin >> row;
            for (int j = 0; j < l; j++) {
                if (row[j] == '0') {
                    vec[i][j] = 0;
                } else {
                    vec[i][j] = 1;
                }
            }
        }

        vector<vector<int>> expected(n, vector<int>(l, 0));
        for (int i = 0; i < n; i++) {
            string row = "";
            cin >> row;
            for (int j = 0; j < l; j++) {
                if (row[j] == '0') {
                    expected[i][j] = 0;
                } else {
                    expected[i][j] = 1;
                }
            }
        }

        bool result = true;
        int cnt = 0;
        for (int j = 0; j < l; j++) {
            int originalAn = 0;
            for (int i = 0; i < n; i++) {
                if (vec[i][j] == 0) { originalAn++; }
            }
            int expectedAn = 0;
            for (int i = 0; i < n; i++) {
                if (expected[i][j] == 0) { expectedAn++; }
            }
            if (expectedAn != originalAn && expectedAn != n - originalAn) {
                result = false;
                break;
            }
            if (expectedAn != originalAn && expectedAn == n - originalAn) {
                cnt++;
            }
        }
        if (result) {
            cout << cnt << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
}