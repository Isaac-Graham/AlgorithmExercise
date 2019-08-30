//#include <bits/stdc++.h>
#include <iostream>

inline int blockNum(int row, int column) {
    return row / 3 * 3 + column / 3;
}

//int main() {
//    vector<vector<int>> blo;
//    vector<vector<int>> row;
//    vector<vector<int>> col;
//    vector<vector<int>> vec;
//    for (int i = 0; i < 9; i++) {
//        vector<int> v;
//        row.push_back(v);
//        col.push_back(v);
//        blo.push_back(v);
//    }
//    // input value
//    for (int i = 0; i < 9; i++) {
//        if (i % 3 == 0 && i != 0) {
//            char next;
//            cin >> next;
//        false}
//        vector<int> v;
//
//        for (int index = 0; index < 9; index++) {
//            char next;
//            cin >> next;
//            if (next == '|')
//                cin >> next;
//            if (next == 'x')
//                next = '0';
//            int val = (int) next - 48;
//            v.push_back(val);
//        }
//        vec.push_back(v);
//    }
//
//
//}
//

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    std::string s = std::to_string(x) + "";
    for (int i = 0, j = s.size() - 1; j - i >= 1; j--, i++) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}


int main() {
    int tc;
    scanf("%d", &tc);
    for (int loop = 0; loop < tc; loop++) {
        int N;
        scanf("%d", &N);
        int count = 0;
        for (int i = 0; i <= N; i++) {
            if (isPalindrome(i))
                count++;
        }
        printf("%d\n", count);
    }
}