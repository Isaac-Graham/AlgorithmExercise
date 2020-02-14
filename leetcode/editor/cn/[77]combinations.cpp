//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool call_back(vector<int> &vec, int n) {
        int pointer = vec.size() - 1;
        int limit = n;
        while (vec[pointer] == limit) {
            if (pointer == 0) {
                return false;
            }
            pointer--;
            limit--;
        }
        vec[pointer++]++;
        while (pointer < vec.size()) {
            vec[pointer] = vec[pointer - 1] + 1;
            pointer++;
        }
        return true;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec(k);
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = i + 1;
        }
        while (true) {
            res.push_back(vec);
            if (vec[k - 1] == n) {
                if (!call_back(vec, n)) {
                    break;
                }
            } else {
                vec[k - 1]++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int fac(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fac(n - 1);
}

int com(int n, int k) {
    return fac(n) / fac(k) / fac(n - k);
}

int main() {
    Solution *s = new Solution();
    for (int n = 2; n <= 10; n++) {
        for (int k = 1; k < n; k++) {
            assert(s->combine(n, k).size() == com(n ,k));
        }
    }
//    vector<vector<int>> res = s->combine(2, 1);
//    for (auto r: res) {
//        for (auto c: r) {
//            cout << c << " ";
//        }
//        cout << endl;
//    }
}