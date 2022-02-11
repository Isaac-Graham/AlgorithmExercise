//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。 
//
// 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// s.length <= 40000 
// 
//
// 注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-
//repeating-characters/ 
// Related Topics 哈希表 字符串 滑动窗口 👍 366 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int left = 0;
        int right = 0;
        int maxLen = 1;

        unordered_map<char, bool> map;
        while (right < s.size() && left <= right) {
            char charMet = s[right];
            if (map.find(charMet) == map.end() || map[charMet] == false) {
                maxLen = max(maxLen, right - left + 1);
                // 不存在
                map[charMet] = true;
                right++;
            } else {
                map[s[left]] = false;
                left++;
            }
        }
        return max(maxLen, right - left);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->lengthOfLongestSubstring("abcabcabc") << endl;
    cout << s->lengthOfLongestSubstring("") << endl;
    cout << s->lengthOfLongestSubstring("a") << endl;
    cout << s->lengthOfLongestSubstring("aaaa") << endl;
    cout << s->lengthOfLongestSubstring("ababbaacd") << endl;
}