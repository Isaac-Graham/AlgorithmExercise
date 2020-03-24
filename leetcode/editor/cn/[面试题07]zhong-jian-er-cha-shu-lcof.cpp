//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
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
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
public:
    unordered_map<int, int> preorderMap;
    unordered_map<int, int> inorderMap;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        for (int index = 0; index < preorder.size(); index++) {
            preorderMap.insert(make_pair(preorder[index], index));
        }
        for (int index = 0; index < inorder.size(); index++) {
            inorderMap.insert(make_pair(inorder[index], index));
        }
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preEnd == preBegin || preBegin >= preorder.size() || inBegin >= preorder.size()) {
            return nullptr;
        }
        int root = preorder[preBegin];
        TreeNode *rootNode = new TreeNode(root);
        if (preEnd - preBegin == 1) {
            return rootNode;
        }
        int rootIndexInorder = inorderMap.find(root)->second;
        int leftSizePreorder = rootIndexInorder - preBegin;

        rootNode->left = buildTree(preorder, inorder, preBegin + 1, preBegin + 1 + leftSizePreorder,
                                   rootIndexInorder - leftSizePreorder, rootIndexInorder);
        rootNode->right = buildTree(preorder, inorder, preBegin + 1 + leftSizePreorder, preorder.size(),
                                    rootIndexInorder + 1, inorder.size());
        return rootNode;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> preorder = {1, 2};
    vector<int> inorder = {1, 2};
    TreeNode *root = s->buildTree(preorder, inorder);

    cout << root->val << endl;
}