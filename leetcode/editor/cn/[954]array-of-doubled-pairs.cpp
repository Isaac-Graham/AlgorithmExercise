//给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i 
//+ 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。 
//
// 
//
// 示例 1： 
//
// 
//输入：arr = [3,1,3,6]
//输出：false
// 
//
// 示例 2： 
//
// 
//输入：arr = [2,1,2,6]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：arr = [4,-2,2,-4]
//输出：true
//解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= arr.length <= 3 * 10⁴ 
// arr.length 是偶数 
// -10⁵ <= arr[i] <= 10⁵ 
// 
// Related Topics 贪心 数组 哈希表 排序 👍 117 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct item {
    int value;
    int status; // 0: 无. 1: 只存在v = 1/2 value。 2: 只存在v = 2value . 3: 存在v = 1/2 value AND v' = 2value
};

class Solution {
private:
    inline bool hasLeft(int x, unordered_map<int, item *> map) {
        if (x % 2 == 1) return false;
        return map.find(x / 2) != map.end();
    }

    inline bool hasRight(int x, unordered_map<int, item *> map) {
        return map.find(x * 2) != map.end();
    }

public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, item *> map;

        for (auto y: arr) {
            int status = 0;
            if (hasLeft(y, map)) {
                status += 1;
                if (map[y / 2]->status)
            }
            if (hasRight(y, map)) {
                status += 2;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
}