//
// Created by Isc on 2020/8/23.
//

#include <bits/stdc++.h>

using namespace std;

int minCut(int begin, int end, vector<vector<int>> &dp) {
    if (begin >= dp.size() || begin > end || end >= dp.size()) {
        return 0;
    }
    vector<int> nums;
    for (int i = 0; i < dp[begin].size(); ++i) {
        if (dp[begin][i] >= begin && dp[begin][i] <= end) {
            nums.push_back(minCut(dp[begin][i] + 1, end, dp));
        }
    }
    if (nums.empty())
        return 0;
    int minNumber = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        minNumber = min(minNumber, nums[i]);
    }
    return 1 + minNumber;
}

int main() {
    string str;
    cin >> str;
    int testcase = 0;
    cin >> testcase;

    vector<vector<bool>> isHuiwen(str.size(), vector<bool>(str.size(), false));
    for (int i = str.size() - 1; i >= 0; i--) {
        isHuiwen[i][i] = true;
        for (int j = i; j < str.size(); j++) {
            if (str[i] == str[j] && ((j - i < 2) || isHuiwen[i + 1][j - 1])) {
                isHuiwen[i][j] = true;
            }
        }
    }
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            dp[i][j] = isHuiwen[i][j] ? 1 : 0;
        }
    }

    for (int loop = 0; loop < testcase; ++loop) {
        int leftIndex = 0;
        int rightIndex = 0;
        cin >> leftIndex >> rightIndex;
        cout << minCut(leftIndex - 1, rightIndex - 1, isHuiwen) << endl;
    }
}