//
// Created by Isc on 2020/8/19.
//

#include <bits/stdc++.h>

using namespace std;

bool isBST(int root, int target, vector<int> &lch, vector<int> &rch) {
    if (root <= 0) {
        return false;
    } else if (root == target) {
        return true;
    }
    return isBST(root > target ? lch[root] : rch[root], target, lch, rch);
}

int maxTop(int node1, int node2, vector<int> &lch, vector<int> &rch) {
    if (node1 > 0 && node2 > 0 && isBST(node1, node2, lch, rch)) {
        int left = maxTop(node1, lch[node2], lch, rch);
        int right = maxTop(node1, rch[node2], lch, rch);
        cout << node1 << " " << node2 << "  " << left << " " << right << endl;
        return left + right + 1;
    }
    return 0;
}

int updateRoot(int root, vector<int> &lch, vector<int> &rch) {
    static int res = 0;
    if (root <= 0) {
        return 0;
    }
    res = max(res, maxTop(root, root, lch, rch));
    updateRoot(lch[root], lch, rch);
    updateRoot(rch[root], lch, rch);
    return res;
}

int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    int p = 0;
    vector<int> lch(n + 1, 0);
    vector<int> rch(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p;
        cin >> lch[p] >> rch[p];
    }
    cout << updateRoot(root, lch, rch) << endl;
}