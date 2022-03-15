//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 数组 动态规划 矩阵 👍 1070 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        int maxValue = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (matrix[i][j] == '0') continue;
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    maxValue = max(maxValue, dp[i][j]);
                    continue;
                }
                int minLen = INT_MAX;

                minLen = min(minLen, dp[i - 1][j - 1]);
                minLen = min(minLen, dp[i - 1][j]);
                minLen = min(minLen, dp[i][j - 1]);

                dp[i][j] = minLen + 1;
                maxValue = max(maxValue, dp[i][j]);
            }
        }

        return maxValue * maxValue;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<char>> vec = {{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    s->maximalSquare(vec);
}