//
// Created by Isc on 2020/8/12.
//

#include <bits/stdc++.h>

using namespace std;
const vector<vector<char>> solution = {
        {'W', 'B', 'T', 'W', 'B', 'T', 'W', 'B', 'T'},
        {'W', 'T', 'B', 'W', 'T', 'B', 'W', 'T', 'B'},
        {'T', 'W', 'B', 'T', 'W', 'B', 'T', 'W', 'B'},
        {'T', 'B', 'W', 'T', 'B', 'W', 'T', 'B', 'W'},
        {'B', 'W', 'T', 'B', 'W', 'T', 'B', 'W', 'T'},
        {'B', 'T', 'W', 'B', 'T', 'W', 'B', 'T', 'W'}
};


int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 0; loop < testcase; loop++) {
        vector<char> vec(9, ' ');
        for (int i = 0; i < 7; i++) {
            string str = "";
            cin >> str;
            vec[str[0] - '1'] = str[1];
        }
        bool res = false;
        for (int i = 0; i < solution.size(); i++) {
            int unmatchNumber = 0;
            for (int index = 0; index < solution[i].size(); index++) {
                if (solution[i][index] != vec[index]) {
                    unmatchNumber++;
                }
            }
            if (unmatchNumber <= 2) {
                res = true;
                break;
            }
        }
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}