//
// Created by Isc on 2020/7/24.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int capacity = 0;// n克面粉
    int goodsKinds = 0; // m种粽子
    cin >> capacity >> goodsKinds;
    vector<int> amount(goodsKinds + 1, 0); // 每个物品最多有多少件
    vector<int> cost(goodsKinds + 1, 0); // 每个粽子占用多少空间(多少面粉)
    vector<int> weight(goodsKinds + 1, 0); // 每个粽子能卖多少钱(价值)
    cin >> cost[0] >> weight[0];
    amount[0] = capacity / cost[0];
    for (int i = 1; i <= goodsKinds; i++) {
        int currentMaterialNumber = 0;
        int costMaterialNumber = 0;
        cin >> currentMaterialNumber >> costMaterialNumber;
        cin >> cost[i] >> weight[i];
        amount[i] = min(capacity / cost[i], currentMaterialNumber / costMaterialNumber);
    }

    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i <= goodsKinds; i++) {
        for (int j = capacity; j >= 0; j--) {
            for (int k = 0; k <= amount[i]; k++) {
                if (j - k * cost[i] >= 0)
                    dp[j] = max(dp[j], dp[j - k * cost[i]] + k * weight[i]);
                else break;
            }
        }
    }
    cout << dp[capacity] << endl;
}



