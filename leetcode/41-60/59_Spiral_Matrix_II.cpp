//
// Created by Isaac_Chen on 2020/1/10.
//

#include <bits/stdc++.h>

using namespace std;

enum State {
    UP, RIGHT, DOWN, LEFT
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            res.push_back(*(new vector<int>(n, 0)));
        }
        State state = RIGHT;
        int i = 0;
        int j = 0;
        for (int value = 1; value <= pow(n, 2); value++) {
            res[i][j] = value;
            if (state == RIGHT) {
                if (j + 1 >= n || res[i][j + 1] != 0) {
                    state = DOWN;
                    i++;
                } else
                    j++;
            } else if (state == DOWN) {
                if (i + 1 >= n || res[i + 1][j] != 0) {
                    state = LEFT;
                    j--;
                } else
                    i++;
            } else if (state == LEFT) {
                if (j - 1 < 0 || res[i][j - 1] != 0) {
                    state = UP;
                    i--;
                } else
                    j--;
            } else {
                if (i - 1 < 0 || res[i - 1][j] != 0) {
                    state = RIGHT;
                    j++;
                } else i--;
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    const int n = 5;
    vector<vector<int>> res = s->generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}