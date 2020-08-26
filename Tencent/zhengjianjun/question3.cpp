//
// Created by Isc on 2020/8/24.
//

#include <bits/stdc++.h>

using namespace std;

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
    return v;
}