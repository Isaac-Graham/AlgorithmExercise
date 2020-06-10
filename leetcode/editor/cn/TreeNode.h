//
// Created by Isc on 2020/6/11.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void preOrder() {
        cout << val << " ";
        if (left != nullptr) {
            left->preOrder();
        }
        if (right != nullptr) {
            right->preOrder();
        }
    }

    void postOrder() {
        if (left != nullptr) {
            left->postOrder();
        }
        if (right != nullptr) {
            right->postOrder();
        }
        cout << val << " ";
    }

    void inOrder() {
        if (left != nullptr) {
            left->postOrder();
        }
        cout << val << " ";
        if (right != nullptr) {
            right->postOrder();
        }
    }

    void levelOrder() {
        struct Item {
            int level;
            TreeNode *node;

            Item(int level, TreeNode *node) : level(level), node(node) {}
        };
        queue<Item *> q;
        q.push(new Item(0, this));
        while (!q.empty()) {
            Item *top = q.front();
            q.pop();
            if (top->node != nullptr) {
                cout << top->node->val << " ";
                if (top->node->left != nullptr) {
                    q.push(new Item(top->level + 1, top->node->left));
                } else {
                    q.push(new Item(top->level + 1, nullptr));
                }
                if (top->node->right != nullptr) {
                    q.push(new Item(top->level + 1, top->node->right));
                } else {
                    q.push(new Item(top->level + 1, nullptr));
                }
            } else
                cout << "nullptr ";

        }
    }
};

#endif //LEETCODE_TREENODE_H
