//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
// Related Topics 并查集 数组 哈希表 👍 1067 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> map;
        for (auto i: nums) {
            map.insert(i);
        }

        int max = INT_MIN;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (map.find(*i - 1) != map.end()) { continue; }
            int cnt = 0;
            int j = *i + 1;
            while (map.find(j) != map.end()) {
                j++;
                cnt++;
            }
            if (max < cnt + 1) {
                max = cnt + 1;
            }
        }
        return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<int>> vec = {
            {},
            {100, 4, 200, 1, 3, 2},
            {1,   1, 1,   1, 1, 2},
            {1,   1, 1,   1, 1, 1, 1, 1, 1, 1, 1},
            {1,   2, 3,   4, 4, 4, 4, 4, 4, 4},
            {1,   2, 3,   3, 4, 4, 5},
            {1,   2},
            {1},
    };
    for (auto i = vec.begin(); i != vec.end(); i++) {
        int res = s->longestConsecutive(*i);
        cout << res << endl;
    }

}