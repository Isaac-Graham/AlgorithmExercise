//
// Created by Isaac Graham on 8/7/2019.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> block_visit;
    vector<vector<bool>> row_visit;
    vector<vector<bool>> col_visit;
    vector<vector<int>> v;

    inline int blockNum(int row, int column) {
        return row / 3 * 3 + column / 3;
    }

// 回溯函数
    void back(int &r, int &c) {
        for (; c >= 0; c--) {

        }
    }

    void solveSudoku(vector<vector<char>> &board) {
//        vector<vector<bool>> block_visit;
//        vector<vector<bool>> row_visit;
//        vector<vector<bool>> col_visit;

        for (int index = 0; index < 9; index++) {
            block_visit.emplace_back(vector<bool>(10));
            row_visit.emplace_back(vector<bool>(10));
            col_visit.emplace_back(vector<bool>(10));
        }


//        vector<vector<int>> v;
        for (int r = 0; r < 9; r++) {
            vector<int> vec(9);
            for (int c = 0; c < 9; c++) {
                vec[c] = board[r][c] == '.' ? 0 : -1 * ((int) board[r][c] - 48);
                if (vec[c] != 0) {
                    row_visit[r][vec[c]] = true;
                    col_visit[c][vec[c]] = true;
                    block_visit[blockNum(r, c)][vec[c]] = true;
                }
            }
            v.push_back(vec);
        }


        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                int num = v[row][col];
                if (num == 0)
                    continue;
                for (int i = 1; i <= 9; i++) {
                    if (row_visit[row][num] || col_visit[col][num] || block_visit[blockNum(row, col)][num]) {
                        if (i == 9) {
                            // 回溯
                        } else {
                            continue;
                        }
                    } else {
                        row_visit[row][num] = true;
                        col_visit[col][num] = true;
                        block_visit[blockNum(row, col)][num] = true;
                    }
                }
            }
        }
    }

};

int main() {
    Solution *s = new Solution();
    vector<vector<char>> board = {
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


}