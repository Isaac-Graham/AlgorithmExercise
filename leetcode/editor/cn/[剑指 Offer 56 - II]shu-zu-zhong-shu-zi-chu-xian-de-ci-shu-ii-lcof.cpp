//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [3,4,3,3]
//输出：4
// 
//
// 示例 2： 
//
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10000 
// 1 <= nums[i] < 2^31 
// 
//
// 
// Related Topics 位运算 数组 👍 276 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        vector<int> vec(32, 0);
        for (auto num: nums) {
            for (int i = 0; i < 32; i++) {
                vec[31 - i] += getBitStatus(num, i);
            }
        }

        int res = 0;
        for (auto i: vec) {
            res *= 2;
            if (i % 3 != 0) {
                res += 1;
            }
        }
        return res;
    }

private :
    inline int getBitStatus(int num, int pos) {
        return num & (1 << pos) ? 1 : 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {9, 1, 7, 9, 7, 9, 7};
    cout << s->singleNumber(vec) << endl;
}