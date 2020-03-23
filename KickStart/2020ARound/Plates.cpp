//
// Created by Isaac_Chen on 2020/3/22.
//

#include <bits/stdc++.h>

using namespace std;

struct Item {
    int cost;
    int worth;

    Item(int cost, int worth) {
        this->cost = cost;
        this->worth = worth;
    }
};

int bruteForce(vector<vector<Item *>> &vec, int n, int k, int limit, int row) {
    if (row == n - 1) {
        if (limit > k || limit == 0) {
            return 0;
        } else {
            return vec[row][limit - 1]->worth;
        }
    }
    int res = 0;
    for (int i = 0; i < min(k, limit) + 1; i++) {
        int r = bruteForce(vec, n, k, limit - i, row + 1);
        if (i == 0) {
            res = max(res, r);
        } else {
            res = max(res, r + vec[row][i - 1]->worth);
        }
    }
    return res;
}

int pack(vector<vector<Item *>> &vec, int p) {
    int MAX = 0;
    vector<vector<int>> dp;
    for (int i = 0; i < vec.size() + 1; i++) {
        vector<int> v(p + 1, 0);
        dp.push_back(v);
    }
    // 对于每一组
    for (int i = 1; i < vec.size() + 1; i++) {
        // 对于每一种容量
        for (int v = 0; v < p + 1; v++) {
            // 对于每一个元素
            for (int j = 0; j < vec[i - 1].size(); j++) {
                // 如果当前容量大于物品容量
                if (v >= vec[i - 1][j]->cost) {
                    int val = max(dp[i - 1][v], dp[i - 1][v - vec[i - 1][j]->cost] + vec[i - 1][j]->worth);
                    dp[i][v] = max(val, dp[i][v]);
                }
            }
        }
    }
    return dp[dp.size() - 1][p];
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int t = 1; t <= testCase; t++) {
        int n, k, p;
        scanf("%d%d%d", &n, &k, &p);
        vector<vector<Item *>> vec;
        for (int i = 0; i < n; i++) {
            vector<Item *> v;
            for (int j = 0; j < k; j++) {
                int val = 0;
                scanf("%d", &val);
                if (v.size() == 0) {
                    v.push_back(new Item(1, val));
                } else {
                    v.push_back(new Item(v.size() + 1, val + v.back()->worth));
                }
            }
            vec.push_back(v);
        }
//        printf("Case #%d: %d\n", t, bruteForce(vec, n, k, p, 0));
        printf("Case #%d: %d\n", t, pack(vec, p));
    }
}