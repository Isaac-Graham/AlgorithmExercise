//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    /*
 * 回溯函数
 * 使用set函数对字符串字符进行去重，
 * 使用swap函数交换两个字符
 * */
    void backtrack2(std::string s, int start, std::set<std::string> &res) {
        // 回溯结束条件
        if (start == s.size()) {
            res.insert(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            // 做选择
            std::swap(s[i], s[start]);
            // 进入下一次决策树
            backtrack2(s, start + 1, res);
            // 撤销选择
            std::swap(s[i], s[start]);
        }
    }

public:
    std::vector<std::string> permutation(std::string s) {
        // 去重处理
        std::set<std::string> res;
        backtrack2(s, 0, res);

        return std::vector<std::string>(res.begin(), res.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    string str = "abc";
    string str1 = "aab";
    vector<string> vec = s->permutation(str);
    for (string str : vec) {
        cout << str << endl;
    }
    cout << "########" << endl;
    vec = s->permutation(str1);
    for (string str : vec) {
        cout << str << endl;
    }
    cout << "end" << endl;
}