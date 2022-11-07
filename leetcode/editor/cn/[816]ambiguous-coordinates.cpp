//我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表
//中。 
//
// 原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数
//来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。 
//
// 最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。 
//
// 
//
// 
//示例 1:
//输入: "(123)"
//输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
// 
//
// 
//示例 2:
//输入: "(00011)"
//输出:  ["(0.001, 1)", "(0, 0.011)"]
//解释: 
//0.0, 00, 0001 或 00.01 是不被允许的。
// 
//
// 
//示例 3:
//输入: "(0123)"
//输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 
//3)"]
// 
//
// 
//示例 4:
//输入: "(100)"
//输出: [(10, 0)]
//解释: 
//1.0 是不被允许的。
// 
//
// 
//
// 提示: 
//
// 
// 4 <= S.length <= 12. 
// S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。 
// 
//
// 
//
// Related Topics 字符串 回溯 👍 137 👎 0

#include <bits/stdc++.h>
#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {

        vector<string> res;
        if (s.size() < 4) {
            return res;
        }

        string treatedStr = s.substr(1, s.size() - 2);
        for (int i = 1; i < treatedStr.size(); i++){
            vector<string> left, right;

            divide(left, right, treatedStr, i);
            conquer(left, right, res);
        }


        return res;
    }

    void divide(vector<string>&left, vector<string>&right, string s, int index) {
        string leftStr = s.substr(0, index);
        string rightStr = s.substr( index);

        findAllPossibleNumber(left, leftStr);
        findAllPossibleNumber(right, rightStr);
    }

    void findAllPossibleNumber(vector<string> &res, string s) {
        // 其实这一块就4个规则
        // 1. 整数没有前导零
        // 2. 小数的小数点之前最开始的几个不是重复零 => 只需要看前两个数字就好
        // 3. 小鼠的小数点最末尾不是重复零 => 只需要看最后一个数字就好
        // 4. 特殊判断0.0

        // 再优化判断
        // 只要是00xxxxx就可以加入0.xxxx
        // 只要是xxxxxx0就不可以加入浮点数

        // 所以逻辑就是
        // 1. 如果数字不是0xxx形式的 => 支持整形数
        // 2. 如果数字是xxxxx0的，没有浮点数
        // 3. 如果数字不是xxxxx0，浮点数判断规则如下
        //    3.1 如果数字形如0xxxx => 只有一种浮点是 => 0.xxxxxxx
        //    3.2 否则，s中所有空位都可以带上.
        if (s.size() == 1 || s[0] != '0') {
            // 当s不是'0xxxxx'形式的话, 默认带上整型数
            res.push_back(s);
        }

        // 处理浮点数
        if (s[s.size() - 1] == '0') {
            return;
        }

        if (s[0] == '0') {
            res.push_back(s.substr(0, 1).append(".").append(s.substr(1)));
        } else {
            for (int i = 1; i < s.size(); i++) {
                res.push_back(s.substr(0, i).append(".").append(s.substr(i)));
            }
        }
    }

    void conquer(vector<string>&left, vector<string>&right, vector<string>&res) {
        for (auto & l : left) {
            for (auto & r : right) {
                string newStr;
                newStr = newStr.append("(").append(l).append(", ").append(r).append(")");
                res.push_back(newStr);
            }
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main () {
    Solution *s = new Solution();

    string str = "(0123)";

    vector<string> vec = s->ambiguousCoordinates(str);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}