//给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 示例 1: 
//
// 输入: word1 = "horse", word2 = "ros"
//输出: 3
//解释: 
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2: 
//
// 输入: word1 = "intention", word2 = "execution"
//输出: 5
//解释: 
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
// Related Topics 字符串 动态规划


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        vector<vector<int>> vec;
        for (int i = 0; i < word1.length() + 1; i++) {
            vec.push_back(*new vector<int>(word2.length() + 1));
        }
        for (int i = 0; i < vec.size(); i++) {
            vec[i][0] = i;
        }

        for (int j = 0; j < vec[0].size(); j++) {
            vec[0][j] = j;
        }

        for (int i = 1; i < vec.size(); i++) {
            for (int j = 1; j < vec[0].size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    vec[i][j] = min3(vec[i - 1][j - 1], 1 + vec[i][j - 1], 1 + vec[i - 1][j]);
                } else {
                    vec[i][j] = min3(1 + vec[i - 1][j - 1], 1 + vec[i][j - 1], 1 + vec[i - 1][j]);
                }
            }
        }
//        for(int i = 0; i < vec.size(); i++) {
//            for(int j = 0; j < vec[i].size(); j++) {
//                cout << vec[i][j] << " ";
//            }
//            cout << endl;
//        }
        return vec[word1.length()][word2.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    string word1 = "";
    string word2 = "";
    cout << s->minDistance(word1, word2) << endl;
}