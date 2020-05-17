//
// Created by Isaac_Chen on 2020/4/12.
//


// 没有通过全部样例
#include<bits/stdc++.h>

using namespace std;

int binarySearch(int begin, int end, vector<int> &couponValue, int target) {
    if (couponValue[begin] > target) {
        return 0;
    }
    if (end - begin <= 1) {
        if (couponValue[end] <= target && couponValue[begin] <= target) {
            return max(couponValue[end], couponValue[begin]);
        }
        if (couponValue[end] <= target) {
            return couponValue[end];
        } else if (couponValue[begin] <= target) {
            return couponValue[begin];
        } else {
            return 0;
        }
    }

    int mid = (begin + end) / 2;
    if (couponValue[mid] == target) {
        return couponValue[mid];
    } else if (couponValue[mid] > target) {
        return binarySearch(begin, mid - 1, couponValue, target);
    } else {
        return binarySearch(mid, end, couponValue, target);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> couponValue;
    vector<int> businessValue;
    for (int i = 0; i < n; i++) {
        int input = 0;
        cin >> input;
        couponValue.push_back(input);
    }
    for (int i = 0; i < m; i++) {
        int input = 0;
        cin >> input;
        businessValue.push_back(input);
    }
    sort(couponValue.begin(), couponValue.end());
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int val = binarySearch(0, n - 1, couponValue, businessValue[i]);
        sum += (businessValue[i] - val);
    }
    cout << sum << "\n";
}