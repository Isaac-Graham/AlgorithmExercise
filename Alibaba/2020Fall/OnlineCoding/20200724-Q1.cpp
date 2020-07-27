//
// Created by Isc on 2020/7/24.
//

// 没做出来
// A 0
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> vec(n, 0);
    int Min = INT_MAX;
    int minIndex = 0;
    for (int i = 0; i < vec.size(); i++) {
        int input = 0;
        cin >> input;
        if (input < Min) {
            Min = min(input, Min);
            minIndex = i;
        }
        vec[i] = input;
    }
    if (n == 0) {
        return 1;
    }
    vector<int> newVec;
    for (int i = minIndex; i >= 0; i--) {
        newVec.push_back(vec[i]);
    }
    if (newVec.size() == 0) {
        cout << 0 << endl;
    }
    vector<vector<int>> dp(newVec.size(), vector<int>());
    dp[0].push_back(newVec[0]);
    int maxAns = 1;
    for (int i = 1; i < dp.size(); i++) {
        vector<int> maxRes;
        for (int j = 0; j < dp.size(); j++) {
            if (newVec[i] > newVec[j]) {
                if (dp[j].size() > maxRes.size()) {
                    maxRes = dp[j];
                }
            }
        }
        dp[i] = maxRes;
        dp[i].push_back(newVec[i]);
        int sum = 0;
        for (int j = 0; j < dp[i].size(); j++) {
            sum += dp[i][j];
        }
        maxAns = max(maxAns, sum);
    }
    cout << maxAns + (n - minIndex) *Min << endl;
}