//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
// Related Topics 队列 滑动窗口 单调队列 堆（优先队列） 👍 383 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.empty())return res;
        if (k == 0) return res;
        priority_queue<int, vector<int>, less<int>> pq;
        unordered_map<int, int> map;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            int val = nums[right];
            if (right - left > k - 1) {
                // 先处理最大值
                while (map[pq.top()] == 0) {
                    pq.pop();
                }
                int top = pq.top();
                res.push_back(top);
                map[nums[left]] -= 1;
                left++;
            }
            pq.push(val);
            if (map.find(val) != map.end()) {
                map[val] += 1;
            } else {
                map[val] = 1;
            }
            right++;
        }
        while (map[pq.top()] == 0) {
            pq.pop();
        }
        res.push_back(pq.top());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {1, -1};
    vector<int> res = s->maxSlidingWindow(vec, 1);
    for (auto i: res) {
        cout << i << endl;
    }
}