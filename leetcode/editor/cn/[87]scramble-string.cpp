//给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。 
//
// 下图是字符串 s1 = "great" 的一种可能的表示形式。 
//
//     great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
// 
//
// 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。 
//
// 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。 
//
//     rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
// 
//
// 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。 
//
// 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。 
//
//     rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
// 
//
// 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。 
//
// 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。 
//
// 示例 1: 
//
// 输入: s1 = "great", s2 = "rgeat"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s1 = "abcde", s2 = "caebd"
//输出: false 
// Related Topics 字符串 动态规划


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isScramble(const string &s1, const string &s2) {
        if (s1.empty() && s2.empty()) {
            return true;
        } else if (s1.empty() || s2.empty()) {
            return false;
        } else if (s1.length() != s2.length()) {
            return false;
        }
        vector<vector<vector<bool>>> dp;
        for (int i = 0; i < s1.length(); i++) {
            vector<vector<bool>> vec(s2.length());
            for (int j = 0; j < s2.length(); j++) {
                vec[j] = *new vector<bool>(s2.length() + 1);
            }
            dp.push_back(vec);
        }
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                dp[i][j][1] = s1[i] == s2[j];
                dp[i][j][0] = true;
            }
        }

        for (int length = 2; length <= s1.size(); length++) {
            for (int i = 0; i <= s1.size() - length; i++) {
                for (int j = 0; j <= s1.size() - length; j++) {
                    for (int k = 1; k < length; k++) {
                        /**
                         * left1 == left2
                         * right1 == right2
                         */
                        dp[i][j][length] = (dp[i][j][k] && dp[i + k][j + k][length - k])
                                           || (dp[i][j + length - k][k] && dp[i + k][j][length - k]);
                        if (dp[i][j][length]) {
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution *s = new Solution();
    vector<vector<string>> vec = {
            {"",                  ""},
            {"11",                "00"},
            {"abc",               "cab"},
            {"abcdefghijklmnopq", "efghijklmnopqcadb"},
            {"great",             "rgeat"},
            {"abcde",             "caebd"},
    };
    for (auto v : vec) {
        cout << s->isScramble(v[0], v[1]) << endl;
    }
    cout << "end" << endl;
}