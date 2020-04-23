//
// Created by Isaac_Chen on 2020/4/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

int string2Int(const string &str, int begin, int end) {
    int res = 0;
    for (int i = begin; i <= end; i++) {
        res *= 10;
        int c = str[i] - '0';
        res += c;
    }
    return res;
}

bool isValid(const string &str, int begin, int end) {
    if (end >= str.length()) {
        return false;
    }
    int val = string2Int(str, begin, end);
    return val <= 600 && val >= 1;
}

void printResult(vector<Interval *> &vec, const string &str) {
    for (int i = 0; i < vec.size(); i++) {
        int start = vec[i]->start;
        int end = vec[i]->end;
        for (int j = start; j <= end; j++) {
            cout << str[j];
        }
        if (i != vec.size() - 1)
            cout << "*";
    }
    cout << "\n";
}

bool backTrack(vector<Interval *> &vec, const string &str) {
    while (!vec.empty() && !isValid(str, vec.back()->start, vec.back()->end + 1)) {
        vec.pop_back();
    }
    return !vec.empty();
}


void solve(const string &inputString) {
    if (inputString.length() < 6) {
        return;
    }
    vector<Interval *> vec;
    int index = 0;
    int length = 0;
    while (true) {
        if (vec.size() < 6) {
            if (isValid(inputString, index, index + length)) {
                vec.push_back(new Interval(index, index + length));
                length = 0;
                index = index + length + 1;
            } else {
                length = 0;
                if (!backTrack(vec, inputString)) {
                    break;
                }
                vec.back()->end += 1;
                index = vec.back()->end + 1;
            }
        } else if (vec.size() == 6) {
            Interval *interval = vec.back();
            if (interval->end < inputString.length() - 1) {
                length = 0;
            } else {
                printResult(vec, inputString);
                vec.pop_back();
            }
            if (!backTrack(vec, inputString)) {
                break;
            }
            vec.back()->end += 1;
            index = vec.back()->end + 1;
        }
    }

}

int main() {
    solve("123123132131231");

}