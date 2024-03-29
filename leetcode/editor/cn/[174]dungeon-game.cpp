//
//
// 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿
//过地下城并通过对抗恶魔来拯救公主。 
//
// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。 
//
// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么
//包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。 
//
// 为了尽快到达公主，骑士决定每次只向右或向下移动一步。 
//
// 
//
// 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。 
//
// 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。 
//
// 
// 
// -2 (K) 
// -3 
// 3 
// 
// 
// -5 
// -10 
// 1 
// 
// 
// 10 
// 30 
// -5 (P) 
// 
// 
//
//
// 
//
// 说明: 
//
// 
// 
// 骑士的健康点数没有上限。 
// 
// 任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。 
// Related Topics 数组 动态规划 矩阵 👍 586 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int findMin(vector<vector<int>> &dungeon, vector<vector<int>> &dp, int i, int j) {
        if (i >= dp.size() || j >= dp[0].size()) {
            return INT_MAX;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        if (i == dp.size() - 1 && j == dp[i].size() - 1) {
            if (dungeon[i][j] > 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = -1 * dungeon[i][j] + 1;
            }
        } else {
            int minPath = min(findMin(dungeon, dp, i + 1, j), findMin(dungeon, dp, i, j + 1));
            if (minPath > dungeon[i][j]) {
                dp[i][j] = minPath - dungeon[i][j];
            } else {
                dp[i][j] = 1;
            }
        }
        return dp[i][j];
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 1;
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));

        return findMin(dungeon, dp, 0, 0);;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();

    vector<vector<int>> vec = {
            {0, 0, 0},
            {1, 1, -1}
    };
    cout << s->calculateMinimumHP(vec) << endl;
}