//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。 
//
// 示例: 
//
// 输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"] 
// Related Topics 字符串 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool valid(const string &s) {
        if (s.empty()) {
            return false;
        } else if (s[0] == '0' && s.length() > 1) {
            return false;
        } else if (s.length() > 3) {
            return false;
        }
        int val = stoi(s);
        return val <= 255 && val >= 0;
    }

public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> res;
        for (int i = 1; i <= 3 && i < s.size(); i++) {
            if (!valid(s.substr(0, i))) {
                continue;
            }
            for (int j = 1; j <= 3 && i + j < s.size(); j++) {
                if (!valid(s.substr(i, j))) {
                    continue;
                }
                for (int k = 1; k <= 3 && i + j + k < s.size(); k++) {
                    if (!valid(s.substr(i + j, k))) {
                        continue;
                    }
                    int l = s.length() - i - j - k;
                    if (valid(s.substr(i + j + k, l))) {
                        stringstream fmt;
                        fmt << s.substr(0, i) << "." << s.substr(i, j) << "."
                            << s.substr(i + j, k) << "." << s.substr(i + j + k, l);
                        res.push_back(fmt.str());
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    string str = "0279245587303";
    vector<string> res = s->restoreIpAddresses(str);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << "end" << endl;
}