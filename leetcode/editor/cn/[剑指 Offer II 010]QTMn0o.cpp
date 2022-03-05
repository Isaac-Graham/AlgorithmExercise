//给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。 
//
// 
//
// 示例 1 : 
//
// 
//输入:nums = [1,1,1], k = 2
//输出: 2
//解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
// 
//
// 示例 2 : 
//
// 
//输入:nums = [1,2,3], k = 3
//输出: 2
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -1000 <= nums[i] <= 1000 
// 
// -10⁷ <= k <= 10⁷ 
// 
// 
//
// 
//
// 注意：本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/ 
// Related Topics 数组 哈希表 前缀和 👍 44 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> preSumCnt;

        int sum = 0;
        preSumCnt[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (preSumCnt.find(sum - k) != preSumCnt.end()) {
                // 找到了
                res += preSumCnt[sum - k];
            }
            if (preSumCnt.find(sum) != preSumCnt.end()) {
                preSumCnt[sum] = preSumCnt[sum] + 1;
            } else {
                preSumCnt[sum] = 1;
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {1, 1, 1};
    cout << s->subarraySum(vec, 2) << endl;
}