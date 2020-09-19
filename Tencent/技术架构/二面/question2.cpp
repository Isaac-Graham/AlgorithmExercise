//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> buildMatrix(int n) {
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    int i = 0;
    int j = 0;
    int index = 1;
    while (index <= n * n) {
        while (matrix[i][j] == 0 && j < n)
            matrix[i][j++] = index++;
        j--;
        i++;
        while (matrix[i][j] == 0 && i < n)
            matrix[i++][j] = index++;
        i--;
        j--;
        while (matrix[i][j] == 0 && j >= 0)
            matrix[i][j--] = index++;
        j++;
        i--;
        while (matrix[i][j] == 0 && i >= 0)
            matrix[i--][j] = index++;
        i++;
        j++;
    }
    return matrix;
}

int main() {
    int n, x, y, m;
    cin >> n >> x >> y >> m;
    vector<vector<int>> matrix = buildMatrix(n);
    for (int i = x - 1; i < x - 1 + m; i++) {
        for (int j = y - 1; j < y - 1 + m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}