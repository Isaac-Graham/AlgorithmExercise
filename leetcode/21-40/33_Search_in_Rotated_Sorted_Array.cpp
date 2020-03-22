//
// Created by Isaac Graham on 8/3/2019.
//
/**
 * 思路是分治+二分
 * 先从中间吧数组分成两部分，这两个部分一定是有一边是有序的，另一边可能有序可能无序
 * 在有序的那一边进行二分搜索，无序的那一边递归地分成两部分
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int> &nums, int target, int begin, int end) {
        if (end >= begin) {
            int mid = (begin + end) / 2;
            if (nums[mid] >= nums[begin]) {
                // 如果左半部分有序
                int result = binary(nums, begin, mid, target);
                if (result != -1)
                    return result;
                else
                    return search(nums, target, mid + 1, end);
            } else {
                // 否则右半部分有序
                int result = binary(nums, mid, end, target);
                if (result != -1)
                    return result;
                else
                    return search(nums, target, begin, mid - 1);
            }
        }
        return -1;
    }

    int binary(vector<int> &nums, int begin, int end, int target) {
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {3, 1};
    cout << s->search(nums, 1);
}
