//给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。 
//
// 示例 1: 
//
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//输出: false 
// Related Topics 字符串 动态规划


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isInterleave(const string &s1, const string &s2, const string &s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> dp;
        for (int i = 0; i < s1.length() + 1; i++) {
            vector<bool> vec(s2.length() + 1);
            dp.push_back(vec);
        }

        dp[0][0] = true;
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = dp[i - 1][0] && s3[i - 1] == s1[i - 1];
        }
        for (int j = 1; j < dp[0].size(); j++) {
            dp[0][j] = dp[0][j - 1] && s3[j - 1] == s2[j - 1];
        }


        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1])
                           || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s->isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;

    cout << "end" << endl;
}