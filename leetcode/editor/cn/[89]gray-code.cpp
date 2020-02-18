//格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。 
//
// 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。 
//
// 示例 1: 
//
// 输入: 2
//输出: [0,1,3,2]
//解释:
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//
//对于给定的 n，其格雷编码序列并不唯一。
//例如，[0,2,3,1] 也是一个有效的格雷编码序列。
//
//00 - 0
//10 - 2
//11 - 3
//01 - 1 
//
// 示例 2: 
//
// 输入: 0
//输出: [0]
//解释: 我们定义格雷编码序列必须以 0 开头。
//     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
//     因此，当 n = 0 时，其格雷编码序列为 [0]。
// 
// Related Topics 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int get_exp(int a) {
        int index = 0;
        for (int i = 0; i < 33; i++) {
            if (a == 0) {
                return index;
            } else {
                index++;
                a = a >> 1;
            }
        }
        return index;
    }

    vector<int> grayCode(int n) {
        if (n == 0) {
            vector<int> res;
            res.push_back(0);
            return res;
        } else if (n == 1) {
            vector<int> res;
            res.push_back(0);
            res.push_back(1);
            return res;
        } else {
            vector<int> res = grayCode(n - 1);
            int exp = get_exp(res[res.size() - 1]);
            for (int i = res.size() - 1; i >= 0; i--) {
                res.push_back(res[i] + pow(2, exp));
            }
            return res;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    for (int n = 0; n < 11; n++) {
        Solution *s = new Solution();
        vector<int> res = s->grayCode(n);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    cout << "end" << endl;
}