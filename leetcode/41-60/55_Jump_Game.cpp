/**
 * 贪心算法
 * 达不到终点当且仅当贪心得出的那个index的值为0
 * 注意，当我到达最后一个位置的时候值为0也算true
 * 具体怎么贪心的详见第45题题解 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int index = 0; index < nums.size() - 1;){
            if (nums[index] == 0)
                return false;
            int next = 1;
            int max = nums[index];
            for (int i = 1; i <= max && i + index < nums.size(); i++) {
                if (i + nums[i + index] > next + nums[next + index] || i + index == nums.size() - 1)
                    next = i;
            }
            index += next;
        }
        return true;
    }
};

int main() {
    vector<int> nums = {3,2,1,0,4};
    Solution *s = new Solution();
    cout << s->canJump(nums) << endl;
}