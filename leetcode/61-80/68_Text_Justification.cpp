//
// Created by Isc on 2020/1/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int length = 0;
        int wordNumber = 0;
        for (int i = 0; i < words.size(); i++) {
            if (length + words[i].size() + wordNumber <= maxWidth) {
                length += words[i].size();
                wordNumber++;
                if (i == words.size() - 1) {
                    string str;
                    for (int index = words.size() - wordNumber; index < words.size() - 1; index++) {
                        str += words[index];
                        str += " ";
                    }
                    str += words[words.size() - 1];
                    while (str.size() < maxWidth) {
                        str += " ";
                    }
                    res.push_back(str);
                }
            } else {
                string str;
                string space;
                if (wordNumber == 1) {
                    str = words[i - wordNumber];
                    while (str.size() < maxWidth) {
                        str += " ";
                    }
                } else {
                    int mod = (maxWidth - length) % (wordNumber - 1);
                    for (int index = 0; index < (maxWidth - length) / (wordNumber - 1); index++) {
                        space += " ";
                    }
                    for (int index = i - wordNumber; index < i - wordNumber + mod; index++) {
                        str += words[index];
                        str += space;
                        str += " ";
                    }
                    for (int index = i - wordNumber + mod; index < i - 1; index++) {
                        str += words[index];
                        str += space;
                    }
                    str += words[i - 1];
                }
                res.push_back(str);

                length = 0;
                wordNumber = 0;
                i--;
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();

    vector<string> words = {"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you",
                            "can", "do", "for", "your", "country"};
    vector<string> res = s->fullJustify(words, 16);
    for (int index = 0; index < res.size(); index++) {
        cout << res[index] << endl;
    }
}