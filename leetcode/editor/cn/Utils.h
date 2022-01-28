//
// Created by Isc on 2020/6/11.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

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

    static TreeNode *buildTree(const vector<int> &vec) {
        if (vec.empty()) {
            return nullptr;
        }
        vector<TreeNode *> nodes;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == NULL) {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(vec[i]));
            }
        }
        for (int i = 0; i < nodes.size(); i++) {
            int leftIndex = (i + 1) * 2 - 1;
            int rightIndex = (i + 1) * 2;
            if (leftIndex > nodes.size()) {
                continue;
            }
            if (nodes[i] == nullptr) {
                continue;
            }
            nodes[i]->left = nodes[leftIndex];
            nodes[i]->right = nodes[rightIndex];
        }
        return nodes[0];
    }
};

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
#endif //LEETCODE_UTILS_H
