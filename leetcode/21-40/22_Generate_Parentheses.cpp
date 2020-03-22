//
// Created by Isaac Graham on 7/31/2019.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        add(arr, "", 0, 0, n);
        return arr;
    }

    void add(vector<string> &arr, const string &current, int left_num, int right_num, int max) {
        if (left_num + right_num >= max * 2) {
            arr.push_back(current);
            return;
        }
        if (left_num < max) {
            add(arr, current + "(", left_num + 1, right_num, max);
        }
        if (right_num < left_num) {
            add(arr, current + ")", left_num, right_num + 1, max);
        }
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> arr = s->generateParenthesis(3);
    cout << arr.size() << endl;
    for (int index = 0; index < arr.size(); index++)
        cout << arr[index] << " ";
}
