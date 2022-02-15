//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [4,1,4,6]
//输出：[1,6] 或 [6,1]
// 
//
// 示例 2： 
//
// 输入：nums = [1,2,10,4,1,4,3,3]
//输出：[2,10] 或 [10,2] 
//
// 
//
// 限制： 
//
// 
// 2 <= nums.length <= 10000 
// 
//
// 
// Related Topics 位运算 数组 👍 538 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int xorRes = 0;
        for (auto num: nums) {
            xorRes ^= num;
        }


        int i = 0;
        while (i < 32) {
            if (getBitStatus(xorRes, i) == 1) break;
            i++;
        }

        int leftXor = 0;
        int rightXor = 0;

        for (auto num: nums) {
            if (getBitStatus(num, i) == 1) {
                leftXor ^= num;
            } else {
                rightXor ^= num;
            }
        }

        return vector<int>{leftXor, rightXor};

    }

private :
    int getBitStatus(int num, int pos) {
        return num & (1 << pos) ? 1 : 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
}