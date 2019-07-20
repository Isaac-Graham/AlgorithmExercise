//
// Created by Isaac Graham on 7/12/2019.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp_array;
        for (int index = 0; index <= s.size(); index++) {
            vector<int> v(p.size() + 1);
            dp_array.push_back(v);
        }

        dp_array[s.size()][p.size()] = 1;

        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool first = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < p.size() && p[j + 1] == '*')
                    dp_array[i][j] = dp_array[i][j + 2] || (first && dp_array[i + 1][j]);
                else
                    dp_array[i][j] = first && dp_array[i + 1][j + 1];
            }
        }
        return dp_array[0][0];
    }

};

int main() {
    Solution *s = new Solution();
    cout << s->isMatch("aab", "c*a*b") << endl;
}