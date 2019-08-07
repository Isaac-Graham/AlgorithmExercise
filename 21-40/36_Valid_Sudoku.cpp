//
// Created by Isaac Graham on 8/7/2019.
//

/**
 * 暴力就完事了
 * 一次迭代
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> block_visit;
        vector<vector<bool>> row_visit;
        vector<vector<bool>> col_visit;

        for (int index = 0; index < 10; index++) {
            block_visit.emplace_back(vector<bool>(9));
            row_visit.emplace_back(vector<bool>(9));
            col_visit.emplace_back(vector<bool>(9));
        }
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char char_value = board[row][col];
                if (char_value == '.')
                    continue;
                int val = (int) char_value - 48;
                int block_num = blockNum(row, col);
                if (block_visit[block_num][val] || row_visit[row][val] || col_visit[col][val]) {
                    return false;
                }
                block_visit[block_num][val] = true;
                row_visit[row][val] = true;
                col_visit[col][val] = true;
            }
        }
        return true;

    }

    inline int blockNum(int row, int column) {
        return row / 3 * 3 + column / 3;
    }
};

int main() {
    vector<vector<char>> v = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution *s = new Solution();
    cout << s->isValidSudoku(v) << endl;
}