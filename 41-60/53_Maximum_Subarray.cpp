//
// Created by isc- on 2019/8/29.
#include <bits/stdc++.h>

class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        long MAX = nums[0];
        long sum = 0;
        for (int num:nums) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            MAX = std::max(MAX,sum);
        }
        return MAX;
    }
};

int main() {
    Solution *s = new Solution();
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s->maxSubArray(nums);
}