//
// Created by Isc on 2020/8/22.
//

#include <bits/stdc++.h>

using namespace std;

int MaximumCopy(const std::vector<size_t> &s, size_t C, size_t &start_index, size_t &end_index) {
    size_t maxSpace = 0;
    // sliding windows
    int leftIndex = 0;
    int rightIndex = 0;
    int totalSize = 0;
    while (leftIndex < s.size() && rightIndex < s.size()) {
        if (s[rightIndex] > C) {
            continue;
        }
        totalSize += s[rightIndex];

        if (totalSize > C) {
            // out of upper limit
            while (leftIndex < rightIndex
                   && totalSize > C) {
                totalSize -= s[leftIndex];
                leftIndex++;
            }
        } else if (totalSize > maxSpace) {
            start_index = leftIndex;
            end_index = rightIndex;
            maxSpace = totalSize;
        }
        rightIndex++;
    }
    return maxSpace == 0 ? -1 : C - maxSpace;
}

int main() {
    vector<size_t> s = {1, 2, 3};
    size_t left;
    size_t right;
    MaximumCopy(s, 7, left, right);
    cout << left << " " << right << endl;
}