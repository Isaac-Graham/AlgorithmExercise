//给定一个非空二叉树，返回其最大路径和。 
//
// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。 
//
// 示例 1: 
//
// 输入: [1,2,3]
//
//       1
//      / \
//     2   3
//
//输出: 6
// 
//
// 示例 2: 
//
// 输入: [-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//输出: 42 
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
    int res = INT_MIN;

    int updateRes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
//        if (root->left == nullptr && root->right == nullptr) {
//            return root->val;
//        }
        int leftMax = updateRes(root->left);
        int rightMax = updateRes(root->right);
        res = max(res,
                  max(root->val, max(root->val + leftMax + rightMax, max(leftMax + root->val, rightMax + root->val))));
        return max(root->val + leftMax + rightMax, max(leftMax + root->val, rightMax + root->val));
    }

public:
    int maxPathSum(TreeNode *root) {
        updateRes(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

struct A {
    int a;
};

int main() {
    A *a = new A();
    cout << sizeof(*a) << endl;
//    Solution *solution = new Solution();
//    vector<int> vec = {5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, 1};
//    TreeNode *root = TreeNode::buildTree(vec);
//    cout << solution->maxPathSum(root) << endl;
//    cout << "end" << endl;
}