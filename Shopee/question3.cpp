//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 获取子串相乘的最大值
     * @param str string字符串 输入的字符串
     * @return int整型
     */
    int getMaxMul(string str) {
        return getMaxMul(getWords(str));
    }

    int getBitNum(char c) {
        return (int) c - (int) 'a';
    };

    int getMaxMul(const vector<string> &words) {
        unordered_map<int, int> hashMap;
        int bitmask = 0;
        int bitNum = 0;
        for (auto word : words) {
            bitmask = 0;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                bitmask |= 1 << getBitNum(ch);
            }

            int value = 0;
            if (hashMap.find(bitmask) != hashMap.end()) {
                value = hashMap[bitmask];
            }
            hashMap[bitmask] = max(value, (int) word.size());
        }
        int maxMul = 0;
        for (auto i = hashMap.begin(); i != hashMap.end(); i++) {
            for (auto j = hashMap.begin(); j != hashMap.end(); j++) {
                if ((i->first & j->first) == 0) {
                    maxMul = max(maxMul, i->second * j->second);
                }
            }
        }
        return maxMul;
    }

    vector<string> getWords(const string &str) {
        vector<string> res;
        for (int length = 1; length < str.length() + 1; length++) {
            for (int i = 0; i < str.length() - length + 1; i++) {
                res.push_back(str.substr(i, length));
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->getMaxMul("sdfdfsgshdfj") << endl;
}