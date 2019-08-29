//
// Created by isc- on 2019/8/29.
//
#include <bits/stdc++.h>
/**
 * 暴力算法，记录每个string的char出现的次数，然后匹配
 */
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, int> hashmap;
        std::vector<std::vector<std::string>> v;
        for (int index = 0; index < strs.size(); index++) {
            std::string s = strs[index];
            sort(s.begin(), s.end());
            if (hashmap.find(s) == hashmap.end()) {
                v.push_back({strs[index]});
                hashmap.insert({s, v.size() - 1});
            } else {
                v[hashmap.at(s)].push_back(strs[index]);
            }
        }
        return v;
    }
};

int main() {
    Solution *s = new Solution();
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> v = s->groupAnagrams(strs);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}