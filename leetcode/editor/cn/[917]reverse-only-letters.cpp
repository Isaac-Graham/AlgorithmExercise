//给你一个字符串 s ，根据下述规则反转字符串： 
//
// 
// 所有非英文字母保留在原有位置。 
// 所有英文字母（小写或大写）位置反转。 
// 
//
// 返回反转后的 s 。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "ab-cd"
//输出："dc-ba"
// 
//
// 
// 
//
// 示例 2： 
//
// 
//输入：s = "a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
// 
//
// 
// 
//
// 示例 3： 
//
// 
//输入：s = "Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
// 
//
// 
//
// 提示 
//
// 
// 1 <= s.length <= 100 
// s 仅由 ASCII 值在范围 [33, 122] 的字符组成 
// s 不含 '\"' 或 '\\' 
// 
// Related Topics 双指针 字符串 👍 141 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        if (s.length() <= 1) return s;
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isChar(s[left])) left++;
            while (left < right && !isChar(s[right]))right--;

            if (left >= right) break;

            if (s[left] != s[right]) {
                char tmp = s[right];
                s[right] = s[left];
                s[left] = tmp;
            }

            left++;
            right--;
        }
        return s;
    }

private:
    inline bool isChar(char c) {
        return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a');
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    cout << s->reverseOnlyLetters("7-91") << endl;
}