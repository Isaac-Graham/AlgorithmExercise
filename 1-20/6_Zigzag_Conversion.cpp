//
// Created by Isaac Graham on 7/9/2019.
//

// 暴力O(n)就完事了

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> two_d_array;
        for (int index = 0; index < numRows; index++) {
            vector<char> v;
            two_d_array.push_back(v);
        }
        int status = 1;
        int row = 0;
        for (int index = 0; index < s.size(); index++) {
            if (status) {
                two_d_array[row++].push_back(s[index]);
                if (row >= numRows - 1) {
                    status = 0;
                    row = numRows - 1;
                }
            } else {
                two_d_array[row--].push_back(s[index]);
                if (row <= 0) {
                    row = 0;
                    status = 1;
                }
            }
        }

        string return_string = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < two_d_array[i].size(); j++) {
                return_string += two_d_array[i][j];

            }
        }
        return return_string;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->convert("AB", 1) << endl;
}