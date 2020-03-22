//
// Created by Isaac Graham on 2019/8/23.
//

/**
 * 贪心算法，用下一跳的距离来贪心
 * 通俗点来说就是，如果我跳了这一跳之后的下一跳的最长距离是我所有的选择中最大的，那我就选这一条
 * 最起码我可以保证我的这个选择可以让我再两跳之内达到max distance
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int count = 0;
        for (int index = 0; index < nums.size() - 1; count++) {
            int next = 1, max = nums[index];
            for (int i = 1; i <= max && i + index < nums.size(); i++) {
                if (i + nums[i + index] > next + nums[next + index] || i + index == nums.size() - 1)
                    next = i;
            }
            index += next;
        }
        return count;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {3, 2, 1};
    cout << s->jump(nums) << endl;
}
