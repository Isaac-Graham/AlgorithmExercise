//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 618 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return divide(nums);
    }

    int divide(vector<int> &vec) {
        if (vec.size() <= 1) return 0;

        int mid = vec.size() / 2;
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < mid; i++) {
            left.push_back(vec[i]);
        }

        for (int i = mid; i < vec.size(); i++) {
            right.push_back(vec[i]);
        }
        int cnt = divide(left) + divide(right);
        return cnt + conquer(left, right, vec);
    }

    int conquer(vector<int> &vec1, vector<int> &vec2, vector<int> &vec) {
        int res = 0;
        int l = 0;
        int r = 0;
        int p = 0;
        while (l < vec1.size() && r < vec2.size()) {
            if (vec1[l] <= vec2[r]) {
                res += r;
                vec[p++] = vec1[l++];
            } else {
                // 逆序
                vec[p++] = vec2[r++];
            }
        }

        while (l < vec1.size()) {
            vec[p++] = vec1[l++];
            res += vec2.size();
        }

        while (r < vec2.size()) {
            vec[p++] = vec2[r++];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {7, 5, 6, 4};
    cout << s->reversePairs(vec) << endl;
}