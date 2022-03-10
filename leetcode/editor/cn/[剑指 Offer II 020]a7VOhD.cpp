//给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 647 题相同：https://leetcode-cn.com/problems/palindromic-substrings/ 
// Related Topics 字符串 动态规划 👍 29 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int findSubStr(const string &s, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        if (i > j) return 1;

        if (s[i] != s[j]) {
            dp[i][j] = -1;
        } else {
            dp[i][j] = findSubStr(s, dp, i + 1, j - 1) == 1;
        }
        return dp[i][j];
    }

public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;

        // 区间[i, j]的回文数量 是否是回文字符串
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < dp.size(); i++) {
            for (int j = i + 1; j < dp[i].size(); j++) {
                if (dp[i][j] == 0) findSubStr(s, dp, i, j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (dp[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->countSubstrings("abc") << endl;
    cout << s->countSubstrings("aaa") << endl;
}