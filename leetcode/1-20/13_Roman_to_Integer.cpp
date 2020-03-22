//
// Created by Isaac Graham on 7/20/2019.
//

#include <bits/stdc++.h>
#include <hash_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int char_int[100];
        char_int['I'] = 1;
        char_int['V'] = 5;
        char_int['X'] = 10;
        char_int['L'] = 50;
        char_int['C'] = 100;
        char_int['D'] = 500;
        char_int['M'] = 1000;
        int inte = 0;
        for (int index = 0; index < s.size(); index++) {
            if (index != s.size() - 1 && char_int[s[index + 1]] > char_int[s[index]]) {
                inte -= char_int[s[index]];
            } else
                inte += char_int[s[index]];
        }
        return inte;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->romanToInt("MCMLXXXVI") << endl;
}