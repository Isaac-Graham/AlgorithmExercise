//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索


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
    vector<int> res;
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        inOrderTraverse(root);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }


    void inOrderTraverse(TreeNode *root) {
        if (root != nullptr) {
            inOrderTraverse(root->left);
            res.push_back(root->val);
            inOrderTraverse(root->right);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(0);
    auto one = new TreeNode(1);
    auto anotherOne = new TreeNode(1);
    auto four = new TreeNode(4);
    auto three = new TreeNode(3);
    auto six = new TreeNode(6);
    one->left = anotherOne;
    cout << s->isValidBST(root) << endl;
    cout << "end" << endl;
}