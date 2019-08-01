//
// Created by Isaac Graham on 8/1/2019.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() == 0) {
            return nums.size();
        } else {
            int p1 = 0;
            for (int p2 = 0; p2 < nums.size(); p2++) {
                if (nums[p2] != val)
                    nums[p1++] = nums[p2];
            }
            return p1;
        }
    }
};

int main() {
    vector<int> nums = {3  };
    Solution *s = new Solution();
    cout << s->removeElement(nums, 3) << endl;
    for (int index = 0; index < nums.size(); index++)
        cout << nums[index] << " ";
}