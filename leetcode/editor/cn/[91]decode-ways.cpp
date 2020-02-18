//一条包含字母 A-Z 的消息通过以下方式进行了编码： 
//
// 'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
// 
//
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。 
//
// 示例 1: 
//
// 输入: "12"
//输出: 2
//解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
// 
//
// 示例 2: 
//
// 输入: "226"
//输出: 3
//解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 
// Related Topics 字符串 动态规划


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int convert(char tens, char digit) {
        if (tens == '0') {
            return 0;
        }
        int val = 0;
        val += (tens - '0') * 10;
        val += digit - '0';
        return val;
    }

public:
    int numDecodings(const string &s) {
        if (s[0] == '0') {
            return 0;
        }
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
            if (i != 0) {
                int val = convert(s[i - 1], s[i]);
                if (val > 0
                    && val <= 26) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[s.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<string> vec = {
            "101",
            "17",
            "0",
            "12",
            "123",
            "226",
            "1",
            "",
    };
    for (int i = 0; i < vec.size(); i++) {
        cout << s->numDecodings(vec[i]) << endl;
    }
    cout << "end" << endl;
}