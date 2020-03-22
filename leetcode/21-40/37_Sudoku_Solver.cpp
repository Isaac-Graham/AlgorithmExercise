//
// Created by Isaac Graham on 8/7/2019.
//

/**
 * 回溯法
 * 刺激
 * 详情看leetcode题解
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> block_visit = {{false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false},
    };
    vector<vector<bool>> row_visit = {{false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
    };
    vector<vector<bool>> col_visit = {{false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
                                      {false, false, false, false, false, false, false, false, false, false},
    };
    vector<vector<int>> v;

    inline int blockNum(int row, int column) {
        return row / 3 * 3 + column / 3;
    }

// 回溯函数
    void back(int &r, int &c) {
        int n = v[r][c];
        v[r][c] = 0;
        row_visit[r][n] = false;
        col_visit[c][n] = false;
        block_visit[blockNum(r, c)][n] = false;
        c--;
        for (; c >= 0; c--) {
            int num = v[r][c];
            if (num < 0)
                continue;
            row_visit[r][num] = false;
            col_visit[c][num] = false;
            block_visit[blockNum(r, c)][num] = false;
            if (num < 9) {
                return;
            }
            v[r][c] = 0;
        }
        r--;
        for (; r >= 0; r--) {
            for (c = 8; c >= 0; c--) {
                int num = v[r][c];
                if (num < 0)
                    continue;
                row_visit[r][num] = false;
                col_visit[c][num] = false;
                block_visit[blockNum(r, c)][num] = false;
                if (num < 9) {
                    return;
                }
                v[r][c] = 0;
            }
        }

    }

    void solveSudoku(vector<vector<char>> &board) {
        for (int r = 0; r < 9; r++) {
            vector<int> vec(9);
            for (int c = 0; c < 9; c++) {
                vec[c] = board[r][c] == '.' ? 0 : -1 * ((int) board[r][c] - 48);
                if (vec[c] != 0) {
                    row_visit[r][-1 * vec[c]] = true;
                    col_visit[c][-1 * vec[c]] = true;
                    block_visit[blockNum(r, c)][-1 * vec[c]] = true;
                }
            }
            v.push_back(vec);
        }


        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (v[row][col] < 0)
                    continue;
                for (int num = v[row][col] + 1; num <= 9; num++) {
                    if (row_visit[row][num] || col_visit[col][num] || block_visit[blockNum(row, col)][num]) {
                        if (num == 9) {
//                            v[row][col] = 0;
                            // 回溯
                            back(row, col);
                            col--;
                            break;
                        } else {
                            continue;
                        }
                    } else {
                        v[row][col] = num;
                        row_visit[row][num] = true;
                        col_visit[col][num] = true;
                        block_visit[blockNum(row, col)][num] = true;
                        break;
                    }
                }
            }
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (v[i][j] < 0)
                        continue;
                    board[i][j] = v[i][j] + '0';
                }
            }
        }
    }

};

int main() {
    Solution *s = new Solution();
//    vector<vector<char>> board = {
//            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };
    vector<vector<char>> board = {
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s->solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] < 0)
                cout << "  ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }


}