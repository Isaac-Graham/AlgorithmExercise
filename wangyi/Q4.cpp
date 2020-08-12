//
// Created by Isc on 2020/8/12.
//

/// 没做出来
#include <bits/stdc++.h>

using namespace std;

struct position {
    int x;
    int y;

    position() {};

    position(int x, int y) : x(x), y(y) {};
};

struct bfsEle {
    position *pos;
    int level;

    bfsEle() {};

    bfsEle(position *p, int l) : pos(p), level(l) {};
};

int manHaDun(position *p1, position *p2) {
    return abs(p1->x - p2->x) + abs(p1->y - p2->y);
}

bool checkBox(position *pos, position *target) {
    return pos->x == target->x && pos->y == target->y;
}

int bfs(vector<vector<char>> &vec, position *pos, position *target) {
    stack<bfsEle *> s;
    s.push(new bfsEle(pos, 0));
    vector<vector<bool>> meet(vec.size(), vector<bool>(vec[0].size(), false));
    meet[pos->x][pos->y] = true;
    while (!s.empty()) {
        bfsEle *top = s.top();
        position *curPos = top->pos;
        s.pop();
        if (checkBox(curPos, target)) {
            return top->level;
        }
        if (curPos->x > 0 && vec[curPos->x - 1][curPos->y] != '#') {
            if (!meet[pos->x - 1][pos->y]) {
                s.push(new bfsEle(new position(curPos->x - 1, curPos->y), top->level + 1));
                meet[curPos->x - 1][curPos->y] = true;
            }
        }
        if (curPos->x < vec.size() - 1 && vec[curPos->x + 1][curPos->y] != '#') {
            if (!meet[pos->x + 1][pos->y]) {
                s.push(new bfsEle(new position(curPos->x + 1, curPos->y), top->level + 1));
                meet[curPos->x + 1][curPos->y] = true;
            }
        }
        if (curPos->y > 0 && vec[curPos->x][curPos->y - 1] != '#') {
            if (!meet[pos->x][pos->y - 1]) {
                s.push(new bfsEle(new position(curPos->x, curPos->y - 1), top->level + 1));
                meet[curPos->x][curPos->y - 1] = true;
            }
        }
        if (curPos->y < vec.size() - 1 && vec[curPos->x][curPos->y + 1] != '#') {
            if (!meet[pos->x][pos->y + 1]) {
                s.push(new bfsEle(new position(curPos->x, curPos->y + 1), top->level + 1));
                meet[curPos->x][curPos->y + 1] = true;
            }
        }
    }
    return -1;
}

int findOutNextBox(vector<position *> &boxes, position *pos) {
    int minDis = INT_MAX;
    int res = -1;
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i] == nullptr) {
            continue;
        }
        int dis = manHaDun(boxes[i], pos);
        if (dis < minDis) {
            minDis = dis;
            res = i;
        }
    }
    return res;
}

bool moveUp(vector<vector<char>> &vec, position *pos, position *targetPos, int minDis) {
    if (pos->x <= 0) {
        return false;
    } else if (vec[pos->x - 1][pos->y] == '#') {
        return false;
    } else {
        position *newPos = new position(pos->x - 1, pos->y);
        int newDis = bfs(vec, newPos, targetPos);
        return newDis < minDis;
    }
}

bool moveDown(vector<vector<char>> &vec, position *pos, position *targetPos, int minDis) {
    if (pos->x >= vec.size() - 1) {
        return false;
    } else if (vec[pos->x + 1][pos->y] == '#') {
        return false;
    } else {
        position *newPos = new position(pos->x + 1, pos->y);
        int newDis = bfs(vec, newPos, targetPos);
        return newDis < minDis;
    }
}


bool moveLeft(vector<vector<char>> &vec, position *pos, position *targetPos, int minDis) {
    if (pos->y <= 0) {
        return false;
    } else if (vec[pos->x][pos->y - 1] == '#') {
        return false;
    } else {
        position *newPos = new position(pos->x, pos->y - 1);
        int newDis = bfs(vec, newPos, targetPos);
        return newDis < minDis;
    }
}

bool moveRight(vector<vector<char>> &vec, position *pos, position *targetPos, int minDis) {
    if (pos->y >= vec[0].size() - 1) {
        return false;
    } else if (vec[pos->x][pos->y + 1] == '#') {
        return false;
    } else {
        position *newPos = new position(pos->x, pos->y + 1);
        int newDis = bfs(vec, newPos, targetPos);
        return newDis < minDis;
    }
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 0; loop < testcase; ++loop) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> vec(m, vector<char>(n, ' '));
        for (int i = 0; i < vec.size(); i++) {
            string str = "";
            cin >> str;
            for (int j = 0; j < vec[i].size(); j++) {
                vec[i][j] = str[j];
            }
        }
        position *pos = nullptr;
        vector<position *> boxes(10, nullptr);
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                if (vec[i][j] == '*') {
                    pos = new position(i, j);
                } else if ('0' <= vec[i][j] && vec[i][j] <= '9') {
                    boxes[vec[i][j] - '0'] = new position(i, j);
                }
            }
        }
        int index = -1;
        int cnt = 0;
        vector<vector<bool>> meet(m, vector<bool>(n, false));
        while ((index = findOutNextBox(boxes, pos)) != -1) {
            if (meet[pos->x][pos->y]) {
                cnt = -1;
                break;
            }
            meet[pos->x][pos->y] = true;
            position *targetPos = boxes[index];
            int minDis = bfs(vec, pos, targetPos);
            if (moveUp(vec, pos, targetPos, minDis)) {
                pos->x--;
                cnt++;
            } else if (moveDown(vec, pos, targetPos, minDis)) {
                pos->x++;
                cnt++;
            } else if (moveLeft(vec, pos, targetPos, minDis)) {
                pos->y--;
                cnt++;
            } else if (moveRight(vec, pos, targetPos, minDis)) {
                pos->y++;
                cnt++;
            } else {
                cnt = -1;
                break;
            }
            if (checkBox(pos, boxes[index])) {
                boxes[index] = nullptr;
                for (int i = 0; i < meet.size(); i++) {
                    for (int j = 0; j < meet[i].size(); j++) {
                        meet[i][j] = false;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}