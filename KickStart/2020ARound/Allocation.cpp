//
// Created by Isaac_Chen on 2020/3/22.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int t = 1; t <= testCase; t++) {
        int house, budge;
        scanf("%d%d", &house, &budge);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < house; i++) {
            int val;
            scanf("%d", &val);
            pq.push(val);
        }
        int cnt = 0;
        while (!pq.empty() && budge >= pq.top()) {
            budge -= pq.top();
            pq.pop();
            cnt++;
        }
        printf("Case #%d: %d\n", t, cnt);
    }
}