//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 示例 1: 
//
// 输入: "A man, a plan, a canal: Panama"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "race a car"
//输出: false
// 
// Related Topics 双指针 字符串


#include <bits/stdc++.h>
#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidCharacter(char c) {
        return isNumber(c) || isLowerCase(c) || isUpperCase(c);
    }

    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    bool isLowerCase(char c) {
        return c >= 'a' && c <= 'z';
    }

    bool isUpperCase(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool isTheSame(char c1, char c2) {
        if (c1 == c2) {
            return true;
        }
        if (isNumber(c1) || isNumber(c2)) {
            return false;
        }
        if (abs((int) c1 - (int) c2) == abs((int) 'a' - (int) 'A')) { return true; }
        return false;
    }

    bool isPalindrome(const string &s) {
        int leftPointer = 0;
        int rightPointer = s.size() - 1;
        while (leftPointer < rightPointer) {
            if (!isValidCharacter(s[leftPointer])) {
                leftPointer++;
                continue;
            } else if (!isValidCharacter(s[rightPointer])) {
                rightPointer--;
                continue;
            }

            if (isTheSame(s[leftPointer], s[rightPointer])) {
                leftPointer++;
                rightPointer--;
            } else {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *solution = new Solution();
    cout << solution->isPalindrome("0P") << endl;
    cout << "end" << endl;
}