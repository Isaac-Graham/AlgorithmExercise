//
// Created by Isc on 2020/7/26.
//


#include <bits/stdc++.h>
#include"../../editor/cn/Utils.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    int numbers = 0;
public:
    int countPairs(TreeNode *root, int distance) {
        getNodes(root, distance);
        return numbers;
    }

    unordered_map<TreeNode *, int> getNodes(TreeNode *root, int distance) {
        unordered_map<TreeNode *, int> res;
        if (root == nullptr) {
            return res;
        }
        if (root->left == nullptr && root->right == nullptr) {
            res[root] = 1;
        }
        unordered_map<TreeNode *, int> leftRes = getNodes(root->left, distance);
        unordered_map<TreeNode *, int> rightRes = getNodes(root->right, distance);
        for (auto leftIt = leftRes.begin(); leftIt != leftRes.end(); ++leftIt) {
            for (auto rightIt = rightRes.begin(); rightIt != rightRes.end(); ++rightIt) {
                if (leftIt->second + rightIt->second <= distance) {
                    numbers++;
                }
            }
        }
        for (auto leftIt = leftRes.begin(); leftIt != leftRes.end(); ++leftIt) {
            res[leftIt->first] = leftIt->second + 1;
        }
        for (auto rightIt = rightRes.begin(); rightIt != rightRes.end(); ++rightIt) {
            res[rightIt->first] = rightIt->second + 1;
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nodeValue = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = TreeNode::buildTree(nodeValue);
    cout << s->countPairs(root, 3) << endl;
}
