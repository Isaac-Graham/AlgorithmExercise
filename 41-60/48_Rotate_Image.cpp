//
// Created by isc- on 2019/8/29.
//
#include<bits/stdc++.h>


class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> vector;
        for (int i = 0; i < n; i++) {
            std::vector<int> v(n);
            vector.push_back(v);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector[j][n - i - 1] = matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = vector[i][j];
            }
        }
    }
};

int main() {
    Solution *s = new Solution();
    std::vector<std::vector<int>> matrix = {
            {0}
    };
    s->rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


