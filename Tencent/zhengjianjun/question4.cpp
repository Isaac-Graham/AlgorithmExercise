//
// Created by Isc on 2020/8/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = pow(2, 29);

struct Tire {
    int value;
    Tire *zero;
    Tire *one;

    Tire() {};

    Tire(int x) : value(x), zero(NULL), one(NULL) {};

    Tire(int x, Tire *left, Tire *right) : value(x), zero(left), one(right) {};
};

vector<int> qianzhuiXor(vector<int> &vec) {
    vector<int> res(1, 0);
    for (int i = 0; i < vec.size(); i++) {
        res.push_back(vec[i] ^ res[res.size() - 1]);
    }
    return res;
}


void insert(int value, Tire *root) {
    int storeValue = value;
    while (value > 0) {
        int bit = value / MAX;
        if (bit == 1) {
            if (root->one == nullptr) {
                root->one = new Tire(1);
            }
            root = root->one;
        } else {
            if (root->zero == nullptr) {
                root->zero = new Tire(0);
            }
            root = root->zero;
        }
        value = value << 1;
    }
    root->value = storeValue;
}

Tire *buildTree(vector<int> &dp) {
    Tire *root = new Tire(0);
    for (int i = 0; i < dp.size(); i++) {
        insert(dp[i], root);
    }
    return root;
}

int query(int value, Tire *root) {
    int qufan = value ^INT_MAX;
    while (qufan > 0) {
        int bit = qufan / MAX;
        if (bit == 1 && root->one != nullptr) {
            root = root->one;
        } else if (bit == 0 && root->zero != nullptr) {
            root = root->zero;
        } else if (bit == 1) {
            root = root->zero;
        } else {
            root = root->one;
        }
        qufan = qufan << 1;
    }
    int res = value ^root->value;
    return res;
}

int main() {
    vector<int> vec = {1, 4, 5, 6};
    vector<int> dp = qianzhuiXor(vec);
    Tire *root = buildTree(dp);
    int maxValue = INT_MIN;
    for (int i = 0; i < dp.size(); i++) {
        maxValue = max(maxValue, query(dp[i], root));
    }
    cout << maxValue << endl;
}