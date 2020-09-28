//
// Created by Isaac_Chen on 2020/9/24.
//

#include <bits/stdc++.h>

using namespace std;
const int dead = 0;
const int live = 1;
const int newLive = 2;
const int newDead = 3;

#define DEAD 0
#define STILL_LIVE 1
#define RELIVE 2
const vector<vector<int>> offset = {{-1, -1},
                                    {-1, 0},
                                    {-1, 1},
                                    {0,  -1},
                                    {0,  1},
                                    {1,  -1},
                                    {1,  0},
                                    {1,  1}};

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int newState = getState(board, i, j);
                moveState(board, i, j, newState);
            }
        }
        refresh(board);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void moveState(vector<vector<int>> &board, int i, int j, int state) {
        if (state == DEAD) {
            board[i][j] = newDead;
        } else if (state == RELIVE) {
            board[i][j] = newLive;
        }
    }

    void refresh(vector<vector<int>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == newLive) {
                    board[i][j] = live;
                } else if (board[i][j] == newDead) {
                    board[i][j] = dead;
                }
            }
        }
    }

    int getState(const vector<vector<int>> &board, int i, int j) {
        int liveNumber = 0;
        int deadNumber = 0;
        for (int index = 0; index < offset.size(); index++) {
            int newI = i + offset[index][0];
            int newJ = j + offset[index][1];
            if (isValid(board, newI, newJ)) {
                int state = board[newI][newJ];
                if (state == 0) {
                    deadNumber++;
                } else if (state == 1) {
                    liveNumber++;
                } else if (state == newLive) {
                    deadNumber++;
                } else if (state == newDead) {
                    liveNumber++;
                } else {
                    cerr << "Error occurs: wired state" << endl;
                }
            }
        }

        if (board[i][j] == dead) {
            if (liveNumber == 3) {
                return RELIVE;
            }
        } else if (board[i][j] == live) {
            if (liveNumber < 2) {
                return DEAD;
            } else if (liveNumber < 4) {
                return STILL_LIVE;
            } else {
                return DEAD;
            }
        } else {
            cerr << "Error occurs: wired state: " << board[i][j] << endl;
        }
        return -1;
    }

    bool isValid(const vector<vector<int>> &board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size();
    }
};


int main() {

    Solution *solution = new Solution();
    vector<vector<int>> board = {{0, 1, 0},
                                 {0, 0, 1},
                                 {1, 1, 1},
                                 {0, 0, 0}};
    solution->gameOfLife(board);
}