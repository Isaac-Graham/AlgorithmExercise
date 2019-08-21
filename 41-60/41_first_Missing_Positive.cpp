//
// Created by Isaac Graham on 2019/8/21.
//

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
                if (nums[value] > 0)
                    nums[value] = -1 * nums[value];
            }

            for (int index = 1; index < nums.size(); index++) {
                if (nums[index] > 0)
                    return index;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {3,4,-1,1};
    cout << s->firstMissingPositive(v) << endl;

}