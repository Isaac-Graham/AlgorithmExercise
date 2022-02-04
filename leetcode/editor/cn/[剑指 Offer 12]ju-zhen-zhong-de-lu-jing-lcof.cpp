//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 数组 回溯 矩阵 👍 498 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0) return false;
        vector<vector<bool>> meet;
        for (int i = 0; i < board.size(); i++) {
            vector<bool> m(board[0].size(), false);
            meet.push_back(m);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]
                    && search(board, word, 0, i, j, meet)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>> &board, string word,
                int index, int i, int j, vector<vector<bool>> &meet) {
        if (index >= word.size())return true;
        if (board.size() == 0) return false;
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) return false;
        if (meet[i][j]) return false;
        if (board[i][j] != word[index]) return false;
        meet[i][j] = true;
        if (search(board, word, index + 1, i - 1, j, meet)
            || search(board, word, index + 1, i + 1, j, meet)
            || search(board, word, index + 1, i, j - 1, meet)
            || search(board, word, index + 1, i, j + 1, meet)) {
            return true;
        }
        meet[i][j] = false;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();

    vector<vector<char>> vec = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'},
    };
    cout << s->exist(vec, "ABCCED") << endl;
}