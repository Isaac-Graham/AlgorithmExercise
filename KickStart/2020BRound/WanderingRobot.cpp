//
// Created by Isaac_Chen on 2020/4/22.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;

inline bool inHole(int x, int y, int holeTop, int holeLeft, int holeDown, int holeRight) {
    return holeTop <= y && y <= holeDown && holeLeft <= x && holeRight >= x;
}

ll combination(int m, int n) {
    if (m < 0 || n < 0) {
        return 0;
    }
    if (m == n && n == 0 && m == 0) {
        return 1;
    }
    return combination(m - 1, n - 1) + combination(m - 1, n);
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 1; loop <= testcase; loop++) {
        int col = 0;
        int row = 0;
        int leftCol = 0;
        int upperRow = 0;
        int rightCol = 0;
        int bottomRow = 0;
        cin >> row >> col >> upperRow >> leftCol >> bottomRow >> rightCol;
        vector<ll> upperRowCombination(col + 1);
        vector<ll> leftColCombination(row + 1);
        double sum = 0;
        ll mostRight = combination(upperRow + rightCol - 3, upperRow - 2);
        upperRowCombination[rightCol] = mostRight;
        ll mostDown = combination(bottomRow + leftCol - 3, bottomRow - 2);
        leftColCombination[bottomRow] = mostDown;
        for (int i = rightCol - 1; i >= leftCol; i--) {
            upperRowCombination[i] = upperRowCombination[i + 1] / (i + upperRow - 2);
            upperRowCombination[i] *= (i + upperRow - 3);
        }
        for (int i = bottomRow - 1; i >= upperRow; i--) {
            leftColCombination[i] = leftColCombination[i + 1] / (i + leftCol - 2);
            leftColCombination[i] *= (i + leftCol - 3);
        }
        if (upperRow == 2) {
            upperRowCombination[1] = 1;
        }
        if (leftCol == 2) {
            leftColCombination[1] = 1;
        }
        if (upperRow != 1) {
            int x = upperRow - 1;
            for (int y = leftCol; y < rightCol + 1; y++) {
                if (y != col) {
                    sum += (double) upperRowCombination[y] / pow(2, x + y - 1);
                } else {
                    sum += 1;
                }
            }
        }
        if (leftCol != 1) {
            int y = leftCol - 1;
            for (int x = upperRow; x < bottomRow + 1; x++) {
                if (x != row) {
                    sum += (double) leftColCombination[x] / pow(2, x + y - 1);
                } else {
                    sum += 1;
                }
            }
        }
        cout << "Case #" << loop << ": " << 1 - sum << "\n";
//        vector<vector<double>> dp;
//        for (int i = 0; i < row + 1; i++) {
//            vector<double> vec(col + 1, 0);
//            dp.push_back(vec);
//        }
//        dp[0][1] = 1;
//        dp[1][0] = 1;
//        for (int i = 1; i < dp.size(); i++) {
//            for (int j = 1; j < dp[i].size(); j++) {
//                if (inHole(i, j, leftCol, upperRow, rightCol, bottomRow)) {
//                    dp[i][j] = 0;
//                } else {
//                    double colCoe = 0.5;
//                    double rowCoe = 0.5;
//                    if (j == col) {
//                        colCoe = 1;
//                    }
//                    if (i == row) {
//                        rowCoe = 1;
//                    }
//                    dp[i][j] = colCoe * dp[i - 1][j] + rowCoe * dp[i][j - 1];
//                }
//            }
//        }
//        cout << "Case #" << loop << ": " << dp[row][col] << "\n";
    }
}