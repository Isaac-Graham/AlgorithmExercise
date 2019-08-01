//
// Created by Isaac Graham on 8/1/2019.
//
/**
 * 最下面注释掉的代码是据说用时0ms的标程
 * 技巧实际上思路也就一个暴力
 * 只是用了点技巧使得减少了比对次数。
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(const string &haystack, const string &needle) {
        return haystack.find(needle);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->strStr("aaaaa","");
}

//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        if(needle.empty()) return 0;
//        int maxi = haystack.size() - needle.size();
//        for(int i = 0; i <= maxi; ++i){
//            if(haystack[i] == needle[0]){
//                int j = 1;
//                for(; j < needle.size(); ++j){
//                    if(haystack[i + j] != needle[j]){
//                        break;
//                    }
//                }
//                if(j == needle.size()){
//                    return i;
//                }
//            }
//        }
//        return -1;
//    }
//};
