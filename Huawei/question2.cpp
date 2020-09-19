//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;

struct Item {
    int index;
    int val;

    Item(int index, int val) : index(index), val(val) {};
};

int largestRectangleArea(vector<int> &heights) {
    stack<Item *> s;
    s.push(new Item(-1, -1));
    int MAX = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] < s.top()->val) {
            while (s.top()->val > heights[i]) {
                Item *top = s.top();
                s.pop();

                MAX = max(MAX, top->val * (i - s.top()->index - 1));
            }
        }
        s.push(new Item(i, heights[i]));
    }
    Item *last = nullptr;
    while (!s.empty()) {
        if (last == nullptr) {
            last = s.top();
            s.pop();
            MAX = max(MAX, last->val);
            continue;
        }
        Item *top = s.top();
        MAX = max(MAX, ((int) heights.size() - 1 - top->index) * last->val);
        last = top;
        s.pop();
    }
    return MAX;
}

int error() {
    cout << 0 << endl;
    return 0;
}

int main() {
    string str;
    cin >> str;
    vector<int> inputWidth;
    vector<int> inputHeight;
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *p;
    char *delim = "[]";
    p = strtok(strs, delim);
    vector<char *> inputString;
    while (p) {
        inputString.push_back(p);
        p = strtok(NULL, delim);
    }
    if (inputString.size() != 3) {
        return error();
    }
    delim = ",";
    strs = inputString[0];
    p = strtok(strs, delim);
    while (p) {
        inputWidth.push_back(atoi(p));
        p = strtok(NULL, delim);
    }
    strs = inputString[2];
    p = strtok(strs, delim);
    while (p) {
        inputHeight.push_back(atoi(p));
        p = strtok(NULL, delim);
    }
    if (inputWidth.size() != inputHeight.size()) {
        return error();
    }

    vector<int> height;
    int length = inputWidth.size();
    for (int i = 0; i < length; i++) {
        int hei = inputHeight[i];
        int wid = inputWidth[i];
        if (wid < 1 || wid > 100 || hei < 1 || hei > 100) {
            return error();
        }
        for (int j = 0; j < wid; j++) {
            height.push_back(hei);
        }
    }
    cout << largestRectangleArea(height) << endl;
}