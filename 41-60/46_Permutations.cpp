//
// Created by Isaac Graham on 2019/8/23.
//

/**
 * 很暴力
 * 之前写过一个“下一个排列”的题目
 * 直接O(n!)时间复杂度下去就好了
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> v;
        long length = factorial(nums.size());
        v.push_back(nums);
        for (long index = 1; index < length; index++) {
            nextPermutation(nums);
            v.push_back(nums);
        }
        return v;
    }

    void nextPermutation(vector<int> &nums) {
        int first_reverse = -1;
        for (int index = nums.size() - 1; index > 0; index--) {
            if (nums[index] > nums[index - 1]) {
                first_reverse = index - 1;
                break;
            }
        }
        if (first_reverse != -1) {
            int tmp = nums[first_reverse];
            int smallest = first_reverse;
            int diff = INT_MAX;
            for (int index = first_reverse + 1; index < nums.size(); index++) {
                if (nums[index] > tmp && nums[index] - tmp <= diff) {
                    smallest = index;
                    diff = nums[index] - tmp;
                }
            }
            nums[first_reverse] = nums[smallest];
            nums[smallest] = tmp;
        }
        for (int offset = 0; offset < (nums.size() - first_reverse - 1) / 2; offset++) {
            int tmp = nums[offset + first_reverse + 1];
            int a = nums[nums.size() - 1 - offset];
            nums[offset + first_reverse + 1] = a;
            nums[nums.size() - 1 - offset] = tmp;
        }
    }

    long factorial(int n) {
        if (n == 1)
            return 1;
        else
            return n * factorial(n - 1);
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> v = s->permute(nums);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}