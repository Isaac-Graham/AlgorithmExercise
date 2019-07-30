//
// Created by Isaac Graham on 7/30/2019.
//
#include <bits/stdc++.h>

// 双指针思路
// 先排序，然后遍历
// 对于每个nums[index]，取他后面的子数组的左右端点作为初始双指针（这两个指针指向的值都比nums[index]大）
// 求和，如果sum == 0，左指针++，右指针--
// 如果sum < 0， 左指针++
// 如果sum > 0， 右指针--
// 代码中一些部分是用来去重的
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int index = 0; index < nums.size() && nums[index] <= 0; index++) {
            // 如果当前数字跟上一个数字相同，会导致重复考虑，跳过
            if (index > 0 && nums[index] == nums[index - 1])
                continue;
            int p1 = index + 1, p2 = (int) nums.size() - 1;
            while (p1 < p2) {
                if (p1 - 1 > index && nums[p1 - 1] == nums[p1]) {
                    p1++;
                    continue;
                }
                if (p2 + 1 < nums.size() && nums[p2 - 1] == p2) {
                    p2--;
                    continue;
                }
                // 判断和的大小
                int sum = nums[p1] + nums[p2] + nums[index];
                if (sum == 0) {
                    v.push_back({nums[index], nums[p1], nums[p2]});
//                    cout << nums[index] << " " << nums[p1] << " " << nums[p2] << endl;
                    p1++;
                    p2--;
                    continue;
                } else if (sum < 0) {
                    p1++;
                    continue;
                } else {
                    p2--;
                    continue;
                }
            }
        }

//        for (int i = 0; i < v.size(); i++) {
//            for (int j = 0; j < 3; j++) {
//                cout << v[i][j] << " ";
//            }
//            cout << endl;
//        }
        return v;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    s->threeSum(nums);
};