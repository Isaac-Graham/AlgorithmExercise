//
// Created by Isaac Graham on 7/30/2019.
//

/**
 * 没有什么思路
 * 把上一题的板子魔改一下就好了
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int min_diff = INT_MAX;
        for (int index = 0; index < nums.size(); index++) {
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
                long result = (long) min_diff - (long) target;
                if (abs(sum - target) < abs(result)) {
                    min_diff = sum;
                }
                if (sum < target) {
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
        return min_diff;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {0, 2, 1, -3};
    cout << s->threeSumClosest(v, 1) << endl;

}