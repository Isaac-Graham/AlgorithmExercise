//
// Created by Isaac_Chen on 2020/1/12.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.reserve(m + 1);
        for (size_t i = 0; i <= m; i++) {
            vector<int> vec(n + 1);
            dp.push_back(vec);
        }
        for (size_t i = 0; i <= m; i++) {
            dp[i][1] = 1;
        }
        for (size_t j = 0; j <= n; j++) {
            dp[1][j] = 1;
        }
        for (size_t i = 2; i <= m; i++) {
            for (size_t j = 2; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int combination(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    } else if (n - k == 1 || k == 1) {
        return n;
    } else {
        return combination(n - 1, k - 1) + combination(n - 1, k);
    }
}

int uniquePaths(int m, int n) {
    if (m == 0 && n == 0) {
        return 0;
    }
    return combination(m + n - 2, n - 1);
}


int main() {
    Solution *s = new Solution();
    for (int n = 1; n < 20; n++) {
        for (int k = 1; k <= n; k++) {
            int i = s->uniquePaths(n, k);
            int j = uniquePaths(n, k);
            if (i == j) {
                cout << "success" << endl;
            } else {
                cout << "fail" << " " << n << " " << k << " " << i << " " << j << endl;
            }
        }
    }
}