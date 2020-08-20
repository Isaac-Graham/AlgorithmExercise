//
// Created by Isc on 2020/8/19.
//

#include <bits/stdc++.h>

using namespace std;

int solution(const string &str1, const string &str2, vector<string> &vec) {
    if (str1.empty() || str2.empty()) {
        return -1;
    }
    int lastStr1Index = -1;
    int lastStr2Index = -1;
    int res = -1;
    for (int i = 0; i < vec.size(); i++) {
        bool str1Meet = false;
        bool str2Meet = false;
        if (vec[i] == str1) {
            if (lastStr2Index != -1) {
                if (res != -1) {
                    res = min(res, i - lastStr2Index);
                } else {
                    res = i - lastStr2Index;
                }
            }
            str1Meet = true;
        }
        if (vec[i] == str2) {
            if (lastStr1Index != -1) {
                if (res != -1) {
                    res = min(res, i - lastStr1Index);
                } else {
                    res = i - lastStr1Index;
                }
            }
            str2Meet = true;
        }
        if (str1Meet) {
            lastStr1Index = i;
        }
        if (str2Meet) {
            lastStr2Index = i;
        }
    }
    if (res != -1) {
        if (lastStr1Index != lastStr2Index) {
            res = min(res, abs(lastStr2Index - lastStr1Index));
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    vector<string> vec(n, "");
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << solution(str1, str2, vec) << endl;
}

