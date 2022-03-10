//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。 
//
// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入: s1 = "ab" s2 = "eidbaooo"
//输出: True
//解释: s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入: s1= "ab" s2 = "eidboaoo"
//输出: False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 10⁴ 
// s1 和 s2 仅包含小写字母 
// 
//
// 
//
// 注意：本题与主站 567 题相同： https://leetcode-cn.com/problems/permutation-in-string/ 
// Related Topics 哈希表 双指针 字符串 滑动窗口 👍 29 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> charOccurTimes; // 记录s1中每个char出现的次数，用于代表全排列
        for (int i = 0; i < s1.length(); ++i) {
            if (charOccurTimes.find(s1[i]) != charOccurTimes.end()) {
                charOccurTimes[s1[i]] = charOccurTimes[s1[i]] + 1;
            } else {
                charOccurTimes[s1[i]] = 1;
            }
        }

        int left = 0;
        unordered_map<char, int> s2Chars;
        for (int right = 0; right < s2.length(); ++right) {

            char newChar = s2[right];

            if (charOccurTimes.find(newChar) == charOccurTimes.end()) {
                // 不存在 => 重新开始
                for (auto kv: s2Chars) {
                    s2Chars[kv.first] = 0;
                }
                left = right + 1;
            } else if (s2Chars.find(newChar) == s2Chars.end() ||
                       s2Chars[newChar] < charOccurTimes[newChar]) {
                // 当前newChar的数量比需要的少

                if (s2Chars.find(newChar) != s2Chars.end()) {
                    s2Chars[newChar] = s2Chars[newChar] + 1;
                } else {
                    s2Chars[newChar] = 1;
                }
            } else if (charOccurTimes[newChar] == s2Chars[newChar]) {
                // 已经饱和，移动左指针
                while (left <= right && s2[left] != newChar) {
                    s2Chars[s2[left]]--;
                    left++;
                }
                left++;
            }
            if (right - left + 1 == s1.length()) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->checkInclusion("ab", "eidbaooo") << endl;
    cout << s->checkInclusion("ab", "eidboaooo") << endl;
    cout << s->checkInclusion("adc", "dcda") << endl;
}