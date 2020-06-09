//根据一棵树的中序遍历与后序遍历构造二叉树。
//
// 注意:
//你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//
// 返回如下的二叉树：
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// Related Topics 树 深度优先搜索 数组


#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void postOrder() {
        if (left != nullptr) {
            left->postOrder();
        }
        if (right != nullptr) {
            right->postOrder();
        }
        cout << val << " ";
    }
    void preOrder() {
        cout << val << " ";
        if (left != nullptr) {
            left->preOrder();
        }
        if (right != nullptr) {
            right->preOrder();
        }
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
    TreeNode *buildTree(vector<int> &inorder, int inorderBegin,
                        vector<int> &postorder, int postorderBegin,
                        int length) {
        if (length == 0) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postorderBegin + length - 1]);
        if (length == 1) {
            return root;
        }
        int index = -1;
        for (int i = inorderBegin; i - inorderBegin < length; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw runtime_error("index should not be -1");
        }
        // inorder: [inorderBegin, index - 1], newLeftLength = index  - inorderBegin, postorder: [postorderBegin, postorderBegin + newLeftLength - 1]
        root->left = buildTree(inorder, inorderBegin, postorder, postorderBegin, index - inorderBegin);
        // inorder: [index + 1, length - 1  + inorderBegin], newRightLength = length - 1 - index + inorderBegin, postorder: [postorderBegin + newLeftLength, postorderBegin + newLeftLength + length - index + inorderBegin]
        root->right = buildTree(inorder, index + 1, postorder, postorderBegin + index - inorderBegin,
                                length - 1 - index + inorderBegin);
        return root;
    }

public:


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, postorder, 0, inorder.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *solution = new Solution();
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = solution->buildTree(inorder, postorder);
    root->preOrder();
    cout << "end" << endl;
}