//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。 
//
// 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1: 
//
// 输入: 1
//输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
// 
//
// 示例 2: 
//
// 输入: 2
//输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0
//.05556,0.02778] 
//
// 
//
// 限制： 
//
// 1 <= n <= 11 
// Related Topics 数学 动态规划 概率与统计 👍 356 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res;
        if (n == 0) return res;

        vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // i个骰子
            for (int j = 1 * i; j < 6 * i + 1; j++) {
                // i个骰子数字总和， 范围：[i, 6*i]

                double val = 0;
                for (int k = 1; k <= 6; k++) {
                    // 枚举第i个骰子扔出的结果
                    if (j - k < 0) continue;
                    val += (dp[i - 1][j - k] * 1 / 6);
                }
                dp[i][j] = val;
            }
        }

        for (int i = n; i < dp[dp.size() - 1].size(); i++) {
            res.push_back(dp[dp.size() - 1][i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    s->dicesProbability(2);
}