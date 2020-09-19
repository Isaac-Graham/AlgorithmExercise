//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;

int binarySearch(int k, int minValue, int maxValue) {
    int begin = 1;
    int end = pow(2, k) - 1;
    while (begin < end) {
        int mid = (begin + end) / 2;
        if (mid <= maxValue && mid >= minValue) {
            return mid;
        } else if (mid < minValue) {
            begin = mid + 1;
        } else if (mid > maxValue) {
            end = mid - 1;
        }
    }
    return -1;
}

int minSubTree(int k, const vector<int> &vec) {
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    for (int i = 0; i < vec.size(); i++) {
        minValue = min(minValue, vec[i]);
        maxValue = max(maxValue, vec[i]);
    }
    return binarySearch(k, minValue, maxValue);
}

void test01() {
    vector<int> vec = {10, 15, 13};
    cout << minSubTree(4, vec) << endl;
}

void test02() {
    vector<int> vec = {10, 9, 8};
    cout << minSubTree(1, vec) << endl;
}

void test03() {
    vector<int> vec = {1, 1, 1};
    cout << minSubTree(2, vec) << endl;
}

void test04() {
    vector<int> vec = {23, 56, 95};
    cout << minSubTree(30, vec) << endl;
}

int main() {
    test01();
    test02();
    test03();
    test04();
}
