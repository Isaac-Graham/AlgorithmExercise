//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//给定如下二叉树，以及目标和 sum = 22， 
//
//               5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
//]
// 
// Related Topics 树 深度优先搜索


#include <bits/stdc++.h>
#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> res;

    void pathSum(vector<int> vec, TreeNode *root, int targetSum, int currentSum) {
        if (root == nullptr) {
            return;
        }
        vec.push_back(root->val);
        currentSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (currentSum == targetSum) {
                res.push_back(vec);
                return;
            }
        }
        if (root->left != nullptr) {
            pathSum(vec, root->left, targetSum, currentSum);
        }
        if (root->right != nullptr) {
            pathSum(vec, root->right, targetSum, currentSum);
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        res.clear();
        vector<int> vec;
        pathSum(vec, root, sum, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *solution = new Solution();

    cout << "end" << endl;
}