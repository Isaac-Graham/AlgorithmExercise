//
// Created by Isc on 2020/8/21.
//

#include <bits/stdc++.h>

using namespace std;

const int k = 3;

struct TreeNode {
    int value;
    struct TreeNode *left, *right;

    TreeNode() {};

    TreeNode(int value, TreeNode *left, TreeNode *right) : value(value), left(left), right(right) {};
};

TreeNode *inOrder(TreeNode *root) {
    static int number = 0;
    if (root == nullptr) {
        return nullptr;
    }
    auto rightRes = inOrder(root->right);
    if (rightRes != nullptr) {
        return rightRes;
    }

    if (number == k - 1) {
        return root;
    }
    number++;
    auto leftRes = inOrder(root->left);
    if (leftRes != nullptr) {
        return leftRes;
    }
    return nullptr;
}

struct TreeNode *find(struct TreeNode *root) {
    // inorder
    if (root == nullptr)
        return nullptr;
    return inOrder(root);
}

void printNode(TreeNode *node) {
    if (node == nullptr) {
        cout << "nullptr" << endl;
    } else {
        cout << node->value << endl;
    }
}

void test01() {
    TreeNode *node1 = new TreeNode(1, nullptr, nullptr);
    printNode(find(node1));
}

int main() {
    test01();
}