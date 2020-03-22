//
// Created by Isaac_Chen on 2020/1/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        const long long m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        const long long n = obstacleGrid[0].size();
        vector<vector<long long>> dp;
        dp.reserve(m + 1);
        for (size_t i = 0; i <= m; i++) {
            vector<long long> vec(n + 1);
            dp.push_back(vec);
        }
        if (m >= 2) {
            dp[2][0] = 1;
        }
        if (n >= 2) {
            dp[0][2] = 1;
        }
//        for (size_t i = 0; i <= m; i++) {
//            dp[i][0] = 1;
//        }
//        for (size_t j = 0; j <= n; j++) {
//            dp[0][j] = 1;
//        }
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        dp[1][1] = 1;
        return dp[m][n];
    }
};

int main() {
    auto *s = new Solution();
    vector<vector<int>> obstacleGrid = {{0}};
//    {{0, 0, 0},
//                                        {0, 1, 0},
//                                        {0, 0, 0}};
    cout << s->uniquePathsWithObstacles(obstacleGrid) << endl;
}