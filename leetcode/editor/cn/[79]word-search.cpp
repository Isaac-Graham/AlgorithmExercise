//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
// 示例:
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.
// Related Topics 数组 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
enum Direction {
    UP, RIGHT, DOWN, LEFT, NODIRECTION
};

struct Coor {
    int x;
    int y;

    Coor(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Solution {
public:
    bool search(vector<vector<bool>> &meet,
                vector<vector<char>> &board,
                Coor *coor,
                const string &word,
                stack<Coor *> &s,
                int curr,
                Direction direction = NODIRECTION) {
        if (coor->x != 0
            && board[coor->x - 1][coor->y] == word[curr]
            && (direction == NODIRECTION)
            && !meet[coor->x - 1][coor->y]) {
            s.push(new Coor(coor->x - 1, coor->y));
            meet[coor->x - 1][coor->y] = true;
            return true;
        } else if (coor->y != board[0].size() - 1
                   && board[coor->x][coor->y + 1] == word[curr]
                   && (direction == NODIRECTION || direction == UP)
                   && !meet[coor->x][coor->y + 1]) {
            s.push(new Coor(coor->x, coor->y + 1));
            meet[coor->x][coor->y + 1] = true;
            return true;
        } else if (coor->x != board.size() - 1
                   && board[coor->x + 1][coor->y] == word[curr]
                   && (direction == NODIRECTION || direction == UP || direction == RIGHT)
                   && !meet[coor->x + 1][coor->y]) {
            s.push(new Coor(coor->x + 1, coor->y));
            meet[coor->x + 1][coor->y] = true;
            return true;
        } else if (coor->y != 0
                   && board[coor->x][coor->y - 1] == word[curr]
                   && (direction == NODIRECTION || direction == UP || direction == RIGHT || direction == DOWN)
                   && !meet[coor->x][coor->y - 1]) {
            s.push(new Coor(coor->x, coor->y - 1));
            meet[coor->x][coor->y - 1] = true;
            return true;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, const string &word) {
        if (board.size() == 0) {
            if (word == "") {
                return true;
            } else {
                return false;
            }
        }
        int curr = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[curr]) {
                    continue;
                } else {
                    stack<Coor *> s;
                    s.push(new Coor(i, j));
                    vector<vector<bool>> meet;
                    for (int index = 0; index < board.size(); index++) {
                        meet.push_back(*new vector<bool>(board[0].size()));
                    }
                    meet[i][j] = true;
                    while (!s.empty()) {
                        Coor *coor = s.top();
//                        s.pop();
                        curr++;
                        if (curr == word.length()) {
                            return true;
                        }
                        if (!search(meet, board, coor, word, s, curr)) {
                            // call_back
                            Coor *last = NULL;
                            while (!s.empty()) {
                                if (last == NULL) {
                                    last = s.top();
                                } else {
                                    Coor *curr_coor = s.top();
                                    Direction direction;
                                    if (curr_coor->x == last->x) {
                                        if (curr_coor->y > last->y) {
                                            direction = LEFT;
                                        } else {
                                            direction = RIGHT;
                                        }
                                    } else {
                                        if (curr_coor->x > last->x) {
                                            direction = UP;
                                        } else {
                                            direction = DOWN;
                                        }
                                    }
                                    meet[last->x][last->y] = false;
                                    if (search(meet, board, curr_coor, word, s, curr, direction)) {
                                        break;
                                    } else {
                                        last = curr_coor;
                                    }
                                }
                                s.pop();
                                curr--;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    const string word = "ASFDECSE";
    cout << s->exist(board, word) << endl;
    cout << 1 << endl;
}