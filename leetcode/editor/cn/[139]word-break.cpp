//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅有小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
// Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划 👍 1364 👎 0


#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<vector<int>> dp;
        for (int i = 0; i < s.length(); ++i) {
            vector<int> vec(s.length(), 0);
            dp.push_back(vec);
        }

        unordered_set<string> set;
        for (auto word: wordDict) {
            set.insert(word);
        }

        return solveDp(s, &dp, &set, 0, s.length() - 1);

    }

    bool solveDp(string s, vector<vector<int>> *dp, unordered_set<string> *set, int i, int j) {
        if (i > j) return false;
        if ((*dp)[i][j] != 0) {
            return (*dp)[i][j] == 1;
        }
        string subStr = s.substr(i, j - i + 1);
        if ((*set).find(subStr) != ((*set).end())) {
            (*dp)[i][j] = 1;
            return true;
        } else {
            for (int gap = i + 1; gap <= j; gap++) {
                bool left = solveDp(s, dp, set, i, gap - 1);
                if (!left) {
                    continue;
                }
                bool right = solveDp(s, dp, set, gap, j);
                if (right) {
                    (*dp)[i][j] = 1;
                    return true;
                }
            }
        }
        (*dp)[i][j] = 2;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<string> vec = {"a", "b"};
    cout << s->wordBreak("ab", vec) << endl;
}