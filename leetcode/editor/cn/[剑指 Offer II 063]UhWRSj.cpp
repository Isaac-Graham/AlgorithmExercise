//在英语中，有一个叫做 词根(root) 的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟
//随着单词 other(其他)，可以形成新的单词 another(另一个)。 
//
// 现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。 
//
// 需要输出替换之后的句子。 
//
// 
//
// 示例 1： 
//
// 
//输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by 
//the battery"
//输出："the cat was rat by the bat"
// 
//
// 示例 2： 
//
// 
//输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
//输出："a a b c"
// 
//
// 示例 3： 
//
// 
//输入：dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa 
//aaa aaaaaa bbb baba ababa"
//输出："a a a a a a a a bbb baba a"
// 
//
// 示例 4： 
//
// 
//输入：dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was 
//rattled by the battery"
//输出："the cat was rat by the bat"
// 
//
// 示例 5： 
//
// 
//输入：dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is 
//accepted"
//输出："it is ab that this solution is ac"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= dictionary.length <= 1000 
// 1 <= dictionary[i].length <= 100 
// dictionary[i] 仅由小写字母组成。 
// 1 <= sentence.length <= 10^6 
// sentence 仅由小写字母和空格组成。 
// sentence 中单词的总量在范围 [1, 1000] 内。 
// sentence 中每个单词的长度在范围 [1, 1000] 内。 
// sentence 中单词之间由一个空格隔开。 
// sentence 没有前导或尾随空格。 
// 
//
// 
//
// 注意：本题与主站 648 题相同： https://leetcode-cn.com/problems/replace-words/ 
// Related Topics 字典树 数组 哈希表 字符串 👍 17 👎 0


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Tire {
public:
    bool isEnd = false;
    string value;
    unordered_map<string, Tire *> succs;

    Tire() {}

    Tire(const string &substr) {
        this->value = substr;
    }

    void preorder() {
        cout << this->value << endl;
        for (auto succ: this->succs) {
            succ.second->preorder();
        }
    }

    string findMinPrefix(const string &str, int len) {
        if (this->isEnd) return this->value;
        if (len > str.length()) return "";

        string substr = str.substr(0, len);
        if (this->succs.find(substr) == this->succs.end()) return "";

        return this->succs[substr]->findMinPrefix(str, len + 1);
    }
};

class Solution {
public:
    Tire *buildTireTree(vector<string> &dictionary) {
        Tire *root = new Tire();

        for (const auto &dic: dictionary) {
            buildTireTree(dic, 1, root);
        }
        return root;
    }

    void buildTireTree(const string &dic, int len, Tire *tire) {
        if (len > dic.length()) {
            tire->isEnd = true;
            return;
        }

        string substr = dic.substr(0, len);
        if (tire->succs.find(substr) == tire->succs.end()) {
            tire->succs[substr] = new Tire(substr);
        }
        buildTireTree(dic, len + 1, tire->succs[substr]);
    }

    string replaceWords(vector<string> &dictionary, string sentence) {
        Tire *tire = buildTireTree(dictionary);
        size_t pos = 0;
        string res = "";
        string root = "";
        while ((pos = sentence.find(' ')) != string::npos) {
            string word = sentence.substr(0, pos);
            if (!(root = tire->findMinPrefix(word, 1)).empty()) {
                res = res + root + " ";
            } else {
                res = res + word + " ";
            }
            sentence.erase(0, pos + 1);
        }
        if (!(root = tire->findMinPrefix(sentence, 1)).empty()) {
            res = res + root;
        } else {
            res = res + sentence ;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed laoreet sem leo, in posuere orci elementum";
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    for (const auto &str : words) {
        cout << str << endl;
    }

    vector<string> vec = {"catt", "cat", "rat"};
    Tire *tire = s->buildTireTree(vec);
    tire->preorder();
}