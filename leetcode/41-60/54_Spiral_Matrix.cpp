//
// Created by isc- on 2019/8/29.
//

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        if (matrix.empty())
            return {};
        std::vector<int> v;
        const int RIGHT = 1;
        const int LEFT = 2;
        const int BOTTOM = 3;
        const int TOP = 4;
        int status = RIGHT;
        std::vector<std::vector<bool>> visited;
        for (int index = 0; index < matrix.size(); index++) {
            visited.push_back(std::vector<bool>(matrix[0].size(), false));
        }
        int total_size = matrix.size() * matrix[0].size();
        int count = 1;
        int i = 0, j = 0;
        while (count < total_size) {
            if (status == RIGHT) {
                while (j < matrix[0].size() - 1 && !visited[i][j + 1]) {
                    v.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    j++;
                    count++;
                }
                status = BOTTOM;
            } else if (status == LEFT) {
                while (j > 0 && !visited[i][j - 1]) {
                    v.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    j--;
                    count++;
                }
                status = TOP;
            } else if (status == TOP) {
                while (i > 0 && !visited[i - 1][j]) {
                    v.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    i--;
                    count++;
                }
                status = RIGHT;
            } else if (status == BOTTOM) {
                while (i < matrix.size() - 1 && !visited[i + 1][j]) {
                    v.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    i++;
                    count++;
                }
                status = LEFT;
            }
        }
        v.push_back(matrix[i][j]);
        return v;
    }
};

int main() {
    Solution *s = new Solution();
    std::vector<std::vector<int>> matrix = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    std::vector<int> v = s->spiralOrder(matrix);
    for (int i : v) {
        std::cout << i << " ";
    }
}