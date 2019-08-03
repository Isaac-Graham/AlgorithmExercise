//
// Created by Isaac Graham on 8/3/2019.
//
/**
 * 两个二分找两个端点
 * 传统二分击中的条件的nums[index] == target
 * 这里加个mid == 0 || nums[mid - 1] < nums[mid](用于找左端点，右端点类似)
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> v = {-1, -1};
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] < nums[mid]) {
                    v[0] = mid;
                }
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            }
        }

        begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] > nums[mid]) {
                    v[1] = mid;
                }
                begin = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            }
        }
        return v;
    }

};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {3, 3, 3};
    vector<int> v = s->searchRange(nums, 3);
    for (int index = 0; index < v.size(); index++) {
        cout << v[index] << " ";
    }
}