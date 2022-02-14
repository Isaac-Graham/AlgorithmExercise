//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 👍 278 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) return n;

        priority_queue<long long, vector<long long>, greater<>> pq;
        unordered_set<long long> set;
        pq.push(1);
        set.insert(1);
        int cnt = 0;

        while (cnt < n - 1) {
            long long top = pq.top();
            pq.pop();
            insert(pq, set, 2 * top);
            insert(pq, set, 3 * top);
            insert(pq, set, 5 * top);
            cnt++;
        }

        return pq.top();

    }

private:
    void insert(priority_queue<long long, vector<long long>, greater<>> &pq, unordered_set<long long> &set,
                long long value) {
        if (set.find(value) != set.end()) return;
        set.insert(value);
        pq.push(value);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->nthUglyNumber(1407) << endl;
}