//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//。
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O",
//"X","X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// 
//
// 示例 2： 
//
// 
//输入：board = [["X"]]
//输出：[["X"]]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] 为 'X' 或 'O' 
// 
// 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 713 👎 0


#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) {
            return;
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                search_and_change(board, 0, i);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[board.size() - 1][i] == 'O') {
                search_and_change(board, board.size() - 1, i);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                search_and_change(board, i, 0);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            if (board[i][board[0].size() - 1] == 'O') {
                search_and_change(board, i, board[0].size() - 1);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void search_and_change(vector<vector<char>> &board, int x, int y) {
        if (x > board.size() - 1 || x < 0) return;
        if (y > board[0].size() - 1 || y < 0) return;
        if (board[x][y] == 'O') {
            board[x][y] = '1';
            search_and_change(board, x + 1, y);
            search_and_change(board, x - 1, y);
            search_and_change(board, x, y + 1);
            search_and_change(board, x, y - 1);
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();

    vector<vector<char>> board = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X', 'O', 'X'}};
    s->solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}