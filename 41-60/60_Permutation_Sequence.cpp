//
// Created by Isaac_Chen on 2020/1/10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<long> permutation;
        permutation.reserve(n);
        permutation.push_back(1);
        for (int index = 2; index < n; index++) {
            permutation.push_back(index * permutation[permutation.size() - 1]);
        }
        string res = "";
        stringstream ss;
        vector<bool> meet(n + 1, false);
        for (int i = n - 1; i > 0; i--) {
            int value = k / permutation[i - 1];
            int mod = k % permutation[i - 1];
            if (k == 0) {
                break;
            } else if (mod != 0) {
                value++;
            }
            for (int index = 0; index <= value; index++) {
                if (meet[index]) {
                    value++;
                    assert(value < n + 1);
                }
            }
            meet[value] = true;
            ss << value;
            k = mod;
        }
        for (int index = n; index > 0; index--) {
            if (!meet[index]) {
                ss << index;
            }
        }
        string str = ss.str();
        res += str;
        return res;
    }

};

int per(int n) {
    if (n == 1) {
        return 1;
    }
    return n * per(n - 1);
}

int main() {
    Solution *s = new Solution();
    const int n = 4;
    for (int k = 1; k <= per(n); k++) {
        cout << s->getPermutation(n, k) << endl;
    }

}