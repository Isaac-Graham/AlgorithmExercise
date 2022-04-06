//设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。设计一种算法，寻找机器人从左上角
//移动到右下角的路径。 
//
// 
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。 
//
// 返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。如果没有可行的路径，返回空数组。 
//
// 示例 1: 
//
// 输入:
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//输出: [[0,0],[0,1],[0,2],[1,2],[2,2]]
//解释: 
//输入中标粗的位置即为输出表示的路径，即
//0行0列（左上角） -> 0行1列 -> 0行2列 -> 1行2列 -> 2行2列（右下角） 
//
// 说明：r 和 c 的值均不超过 100。 
// Related Topics 数组 动态规划 回溯 矩阵 👍 87 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    pair<int, int> invalid = {-1, -1};

    pair<int, int> findOne(vector<vector<int>> &obstacleGrid, int i, int j) {
        if (i != obstacleGrid.size() - 1 && obstacleGrid[i + 1][j] == 0) return {i + 1, j};
        else if (j != obstacleGrid[0].size() - 1 && obstacleGrid[i][j + 1] == 0) return {i, j + 1};
        return invalid;
    }

public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> res;
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return res;
        stack<pair<int, int>> s;
        s.push({0, 0});
        obstacleGrid[0][0] = 2;

        while (!s.empty() && (s.top().first < obstacleGrid.size() - 1 || s.top().second < obstacleGrid[0].size() - 1)) {
            pair<int, int> top = s.top();
            pair<int, int> one = findOne(obstacleGrid, top.first, top.second);
            if (one == invalid) s.pop();
            else {
                s.push(one);
                obstacleGrid[one.first][one.second] = 2;
            }
        }
        if (s.empty()) return res;


        stack<pair<int, int>> ss;
        while (!s.empty()) {
            pair<int, int> top = s.top();
            ss.push(top);
            s.pop();
        }
        while (!ss.empty()) {
            pair<int, int> top = ss.top();
            res.push_back({top.first, top.second});
            ss.pop();
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<int>> vec = {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
    };
    s->pathWithObstacles(vec);
}