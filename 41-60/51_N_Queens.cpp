//
// Created by isc- on 2019/8/29.
//
#include <bits/stdc++.h>
/**
 * 回溯大法好
 */
class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<bool> row(n, false);
        std::vector<bool> col(n, false);
        std::vector<bool> right_diagonal(2 * n, false); // 相加为定值，范围为[0, 2n-2]，开2n是懒得精确算了...
        std::vector<bool> left_diagonal(2 * n, false); // row - col为定值，范围为[-n + 1, n + 1], 所以有offset为 n - 1
        const int offset = n - 1;
        std::vector<int> queens(n, -1);
        bool non_left = false;
        std::string s = "";
        for (int i = 0; i < n; i++) {
            s += ".";
        }
        std::vector<std::vector<std::string>> vec;
        while (!non_left) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!row[i] && !col[j] && !right_diagonal[i + j] && !left_diagonal[i - j + offset]) {
                        queens[i] = j;
                        row[i] = true;
                        col[j] = true;
                        right_diagonal[i + j] = true;
                        left_diagonal[i - j + offset] = true;
                        if (i != n - 1)
                            break;
                        else {
                            std::vector<std::string> v(n, s);
                            for (int index = 0; index < n; index++) {
                                v[index][queens[index]] = 'Q';
                            }
                            vec.push_back(v);
                            row[n - 1] = false;
                            col[queens[n - 1]] = false;
                            right_diagonal[n - 1 + queens[n - 1]] = false;
                            left_diagonal[n - 1 - queens[n - 1] + offset] = false;
                            queens[n - 1] = -1;
                        }
                    }
                    // 不能放皇后的情况
                    while (j == n - 1) {
                        if (i == 0) {
                            non_left = true;
                            i = n;
                            break;
                        }
                        // 删掉上一个皇后
                        int last_j = queens[i - 1];
                        int last_i = i - 1;
                        row[last_i] = false;
                        col[last_j] = false;
                        right_diagonal[last_i + last_j] = false;
                        left_diagonal[last_i - last_j + offset] = false;
                        queens[last_i] = -1;
                        i = last_i;
                        j = last_j;
                    }
                }
            }

        }
        return vec;
    }
};

int main() {
    Solution *s = new Solution();
    std::vector<std::vector<std::string>> v = s->solveNQueens(8);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << std::endl;
        }
    }
}
