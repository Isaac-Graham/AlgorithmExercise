//
// Created by Isaac Graham on 2019/8/22.
//

/**
 * 动态规划问题
 * dp[i][j]代表s[0:i - 1] match p[0:j - 1]
 * 然后写递推方程就好
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        bool dp[s.size() + 1][p.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int j = 1; j <= p.size(); j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }


        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if ((s[i - 1] == p[j - 1] || p[j - 1] == '*' || p[j - 1] == '?') && dp[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (dp[i][j - 1] && p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1];
                else if (dp[i - 1][j] && p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j];
            }
        }


        return dp[s.size()][p.size()];
    }
};

int main() {
    string str = "acdcb";
    string p = "a*c?b";
    Solution *s = new Solution();
    cout << s->isMatch(str, p) << endl;
}