//
// Created by Isaac Graham on 8/1/2019.
//

/**
 * 快慢指针的思维
 * 慢的指针用于指向新数组（其实就是原本的那个数组）
 * 快的指针用于指向旧数组
 * 如果快指针指向的值 > 满指针指向的值，因为数组排序过，所以这个时候快指针指向的值肯定没有被加入新数组
 * update一下就好
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1)
            return (int) nums.size();
        else {
            int p1 = 0;
            for (int p2 = 1; p2 < nums.size(); p2++) {
                if (nums[p2] > nums[p1])
                    nums[++p1] = nums[p2];
            }
            return p1 + 1;
        }
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution *s = new Solution();
    cout << s->removeDuplicates(nums) << endl;
    for (int index = 0; index < nums.size(); index++)
        cout << nums[index] << " ";
}
