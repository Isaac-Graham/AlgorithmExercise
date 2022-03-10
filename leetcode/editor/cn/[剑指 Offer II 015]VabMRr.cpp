//给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 变位词 指字母相同，但排列不同的字符串。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// 
//
// 注意：本题与主站 438 题相同： https://leetcode-cn.com/problems/find-all-anagrams-in-a-
//string/ 
// Related Topics 哈希表 字符串 滑动窗口 👍 15 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    inline int updateDiff(vector<int> &cntP, vector<int> &cntS, int index, int op, int diff) {
        if (cntP[index] == cntS[index] + op)return diff + 1;
        else if (cntP[index] == cntS[index]) return diff - 1;
        return diff;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length()) return res;

        string tmp = s;
        s = p;
        p = tmp;

        vector<int> cntS(26, 0);
        vector<int> cntP(26, 0);
        int diff = 0;

        for (int i = 0; i < s.length(); i++) {
            cntS[s[i] - 'a']++;
            cntP[p[i] - 'a']++;
        }

        for (int i = 0; i < cntS.size(); i++) {
            if (cntS[i] != cntP[i]) diff++;
        }

        if (diff == 0) res.push_back(0);
        for (int i = s.size(); i < p.size(); i++) {
            if (p[i] != p[i - s.size()]) {
                cntP[p[i] - 'a']++;
                diff = updateDiff(cntP, cntS, p[i] - 'a', 1, diff);
                cntP[p[i - s.size()] - 'a']--;
                diff = updateDiff(cntP, cntS, p[i - s.size()] - 'a', -1, diff);
            }
            if (diff == 0) {
                res.push_back(i - s.size() + 1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> res = s->findAnagrams("abab", "ab");
    for (auto r : res) cout << r << " ";
    cout << endl;
}