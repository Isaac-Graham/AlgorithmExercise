//
// Created by Isaac Graham on 8/7/2019.
//
/**
 * 二分就完事了
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (mid == 0 || nums[mid - 1] < target)
                    return mid;
                else
                    end = mid - 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] > target)
                    return mid + 1;
                else
                    begin = mid + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {1};
    cout << s->searchInsert(v, 0);
}