//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可
//能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。 
//
// 
//
// 示例 1: 
//
// 输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi" 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 2³¹ 
// 
// Related Topics 字符串 动态规划 👍 360 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private :
    unordered_set<string, char> map = {
            {"0",  'a'},
            {"1",  'b'},
            {"2",  'c'},
            {"3",  'd'},
            {"4",  'e'},
            {"5",  'f'},
            {"6",  'g'},
            {"7",  'h'},
            {"8",  'i'},
            {"9",  'j'},
            {"10", 'k'},
            {"11", 'l'},
            {"12", 'm'},
            {"13", 'n'},
            {"14", 'o'},
            {"15", 'p'},
            {"16", 'q'},
            {"17", 'r'},
            {"18", 's'},
            {"19", 't'},
            {"20", 'u'},
            {"21", 'v'},
            {"22", 'w'},
            {"23", 'x'},
            {"24", 'y'},
            {"25", 'z'},
    };

public:
    int translateNum(int num) {
        if (num < 10) return 1;
        string numStr = to_string(num);
        vector<int> dp(numStr.size(), 0); // 从[0, i]表示的字符串有多少解法 dp[size() - 1] 为结果

        dp[0] = 1;
        dp[1] = 1;
        if (match(numStr, 0, 1)) dp[1] += 1;

        for (int i = 2; i < dp.size(); i++) {
            int res = 0;
            if (match(numStr, i, i)) res += dp[i - 1];
            if (match(numStr, i - 1, i)) res += dp[i - 2];
            dp[i] = res;
        }
        return dp[dp.size() - 1];

    }

    inline bool match(const string &str, int begin, int end) {
        if (begin > end) return false;
        if (end > str.size() - 1) return false;
        if (begin < 0) return false;

        string substr = str.substr(begin, end - begin + 1);
        return map.find(substr) != map.end();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->translateNum(1) << endl;
}