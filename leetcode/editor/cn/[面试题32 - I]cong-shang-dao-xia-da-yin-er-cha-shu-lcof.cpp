//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回： 
//
// [3,9,20,15,7]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 159 👎 0


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
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            auto node = nodes.front();
            res.push_back(node->val);
            if (node->left != nullptr) nodes.push(node->left);
            if (node->right != nullptr) nodes.push(node->right);
            nodes.pop();
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
}