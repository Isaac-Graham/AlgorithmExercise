//
// Created by Isaac Graham on 8/2/2019.
//

/**
 * 规律是
 * 首先从后往前找，找到第一个nums[index] > nums[index-1]的位置(比如12355中的35这里)
 * 记录下此时的index-1
 * 然后从index-1往后找，找到最远的，同时减去nums[index-1]的值最小的那个位置(比如12355里，我们找到的就是最后一个5)
 * 交换这两个数字(12355 -> 12553)
 * 然后从刚刚的index(注意是Index不是index-1)开始reverse一下就好(12553 -> 12535)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {1, 5, 1};
    s->nextPermutation(v);
    for (int index = 0; index < v.size(); index++) {
        cout << v[index] << " ";
    }
}