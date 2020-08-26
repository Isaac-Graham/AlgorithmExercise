//
// Created by Isc on 2020/8/24.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {};

    TreeNode(int x) : value(x), left(NULL), right(NULL) {};

    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {};
};

class Solution {
public:
    int maxSum;

    int solve(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        int sum = root->value + leftSum + rightSum;
        maxSum = max(maxSum, sum);
        return sum;
    }
};

int main() {
    Solution *s = new Solution();

}