//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。 
//
// 示例： 
//
// 输入: S = "ADOBECODEBANC", T = "ABC"
//输出: "BANC" 
//
// 说明： 
//
// 
// 如果 S 中不存这样的子串，则返回空字符串 ""。 
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。 
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    unordered_map<char, int> map;
    unordered_map<char, int> reserved_map;
    string res;
public:
    int move(const string &s, const string &t, int window_left, int window_right) {
        while (window_left <= window_right && window_left < s.length()) {
            if (map.find(s[window_left]) == map.end()) {
                window_left++;
            } else {
                if (map.at(s[window_left]) > reserved_map.at(s[window_left])) {
                    map[s[window_left]]--;
                    window_left++;
                } else {
                    break;
                }
            }
        }
        string str = s.substr(window_left, window_right - window_left);
        if ((res.empty() || res.length() > str.length()) && str.length() >= t.length()) {
            res = str;
        }
        return window_left;
    }

    string minWindow(const string &s, const string &t) {
        if (t.length() > s.length()) {
            return "";
        }
        int meet = t.length();
        for (int i = 0; i < t.length(); i++) {
            if (map.find(t[i]) == map.end()) {
                reserved_map.insert(make_pair(t[i], 1));
                map.insert(make_pair(t[i], 0));
            } else {
                reserved_map[t[i]]++;
            }
        }
        int window_left = 0;
        int window_right = 0;
        while (window_right < s.length()) {
            if (map.find(s[window_right]) == map.end()) {
                window_right++;
            } else {
//                cout << s[window_right] << map.at(s[window_right]) << endl;
                if (map.at(s[window_right]) < reserved_map.at(s[window_right])) {
                    map[s[window_right]]++;
                    meet--;
                    window_right++;
                    if (meet == 0) {
                        window_left = move(s, t, window_left, window_right);
                    }
                } else {
                    map[s[window_right]]++;
                    window_right++;
                    if (meet <= 0) {
                        window_left = move(s, t, window_left, window_right);
                    }
                }
            }
        }
        if (meet <= 0) {
            move(s, t, window_left, window_right);
        };
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<string> S = {"abbbb", "acbbaca", "bba", "ADOBECODEBANC", "abc", "aa", "a", "", "ab", "a", "a", "ab"};
    vector<string> T = {"aa", "aba", "ab", "ABC", "b", "a", "a", "a", "a", "b", "aa", "b"};
    for (int index = 0; index < S.size(); index++) {
        Solution *s = new Solution();
        cout << s->minWindow(S[index], T[index]) << endl;
    }
    cout << 1 << endl;
}
