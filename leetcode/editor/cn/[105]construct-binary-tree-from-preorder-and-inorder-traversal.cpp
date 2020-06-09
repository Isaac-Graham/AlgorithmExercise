//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组


#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void traverse() {
        if (left != nullptr) {
            left->traverse();
        }
        if (right != nullptr) {
            right->traverse();
        }
        cout << val << " ";
    }
};
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
    TreeNode *buildTree(vector<int> &preorder, int preorderBegin,
                        vector<int> &inorder, int inorderBegin,
                        int length) {
        if (length == 0) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preorderBegin]);
        if (length == 1) {
            return root;
        }
        int index = -1;
        for (int i = inorderBegin; i - inorderBegin < length; ++i) {
            if (inorder[i] == preorder[preorderBegin]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw runtime_error("index should not be -1");
        }
        root->left = buildTree(preorder, preorderBegin + 1, inorder, inorderBegin, index - inorderBegin);
        root->right = buildTree(preorder, preorderBegin + index + 1 - inorderBegin, inorder, index + 1,
                                length - index - 1 + inorderBegin);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = s->buildTree(preorder, inorder);
    root->traverse();
    cout << "end" << endl;
}