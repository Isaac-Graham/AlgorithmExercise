#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int v) {
        this->val = v;
    }
};


class Solution {
public:
    Node *res = nullptr;

    bool findAns(Node *o1, Node *o2, Node *root) {
        if (o1 == o2) {
            res = o1;
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        bool leftSon = findAns(o1, o2, root->left);
        bool rightSon = findAns(o1, o2, root->right);
        if (leftSon && rightSon) {
            res = root;
        } else if ((root->val == o1->val || root->val == o2->val)
                   && (leftSon || rightSon)) {
            res = root;
        }
        return leftSon || rightSon || root->val == o1->val || root->val == o2->val;
    }

};


int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    vector<Node *> nodes(n + 1, new Node());
    for (int i = 1; i < n + 1; i++) {
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < n; i++) {
        int fa = 0;
        int lch = 0;
        int rch = 0;
        cin >> fa >> lch >> rch;
        if (lch != 0) {
            nodes[fa]->left = nodes[lch];
        } else {
            nodes[fa]->left = nullptr;
        }
        if (rch != 0) {
            nodes[fa]->right = nodes[rch];
        } else {
            nodes[fa]->right = nullptr;
        }
    }

    int o1Val, o2Val;
    cin >> o1Val >> o2Val;
    Solution *solution = new Solution();
    solution->findAns(nodes[o1Val], nodes[o2Val], nodes[root]);
    cout << solution->res->val << endl;
}