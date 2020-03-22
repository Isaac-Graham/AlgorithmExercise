//
// Created by Isaac Graham on 2019/8/21.
//

/**
 * 把自己当作hash
 * 第一次遍历判断有没有1
 * 第二次遍历把所有肯定不是答案的都改成1
 * 第三次遍历的时候，遍历到nums[index],然后把nums[nums[index- 1]的值置为负数
 * 第四次遍历的时候找第一个出现的正数坐标
 * 第四次遍历的时候找第一个出现的正数坐标
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        bool has_one = false;
        for (int i :nums) {
            if (i == 1)
                has_one = true;
        }
        if (!has_one)
            return 1;
        else {
            for (int index = 0; index < nums.size(); index++) {
                int i = nums[index];
                if (i <= 0 || i > nums.size()) {
                    nums[index] = 1;
                }
            }
            for (int index = 0; index < nums.size(); index++) {
                int value = abs(nums[index]);
                if (nums[value - 1] > 0)
                    nums[value - 1] = -1 * nums[value - 1];
            }

            for (int index = 0; index < nums.size(); index++) {
                if (nums[index] > 0)
                    return index + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {1, 2, 0};
    cout << s->firstMissingPositive(v) << endl;

}