//
// Created by Isc on 2020/7/21.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxSubBox(vector<vector<int>> &box) {
    if (box.size() < 2) {
        return box.size();
    }
    sort(box.begin(), box.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    for (int i = 0; i < box.size(); i++) {
        for (int j = 0; j < box[i].size(); j++) {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }
    int boxSize = box.size();
    int number = 1;
    vector<int> dp(boxSize + 1, 0);
    for (int i = 1; i <= boxSize; i++) {
        dp[i] = 1;
        number = max(number, dp[i]);
        for (int j = 1; j < i; j++) {
            if (box[j - 1][0] < box[i - 1][0] &&
                box[j - 1][1] < box[i - 1][1] &&
                box[j - 1][2] < box[i - 1][2]) {
                dp[i] = max(dp[i], dp[j] + 1);
                number = max(number, dp[i]);
            }
        }
    }

    for (int i = 0; i < dp.size(); i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return number;
}

int main() {
    vector<vector<int>> box = {{1,  4,  6},
                               {90, 1,  2},
                               {19, 29, 3}};
    cout << getMaxSubBox(box) << endl;
}