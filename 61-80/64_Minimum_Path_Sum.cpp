//
// Created by Isc on 2020/1/14.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        const int m = grid.size();
        if (m <= 0) {
            return 0;
        }
        const int n = grid[0].size();
        vector<vector<int>> dp;
        dp.reserve(m + 1);
        for (int index = 0; index <= m; index++) {
            vector<int> vec(n + 1);
            dp.push_back(vec);
        }
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = INT_MAX;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = INT_MAX;
        }
        dp[0][1] = 0;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> vec = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << s->minPathSum(vec) << endl;
}