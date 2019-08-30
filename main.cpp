#include <bits/stdc++.h>

using namespace std;

inline int blockNum(int row, int column) {
    return row / 3 * 3 + column / 3;
}

int main() {
    vector<vector<int>> blo;
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> vec;
    for (int i = 0; i < 9; i++) {
        vector<int> v;
        row.push_back(v);
        col.push_back(v);
        blo.push_back(v);
    }
    // input value
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            char next;
            cin >> next;
        }
        vector<int> v;

        for (int index = 0; index < 9; index++) {
            char next;
            cin >> next;
            if (next == '|')
                cin >> next;
            if (next == 'x')
                next = '0';
            int val = (int) next - 48;
            v.push_back(val);
        }
        vec.push_back(v);
    }


}