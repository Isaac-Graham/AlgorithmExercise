//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
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
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 173 👎 0


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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> vec;
        if (root == nullptr) return vec;
        vector<vector<TreeNode *> > nodes;
        nodes.push_back(vector<TreeNode *>{root});
        run(nodes);

        for (auto layer: nodes) {
            vector<int> v;
            for (auto node: layer) v.push_back(node->val);
            vec.push_back(v);
        }
        return vec;

    }

private:
    void run(vector<vector<TreeNode *>> &nodes) {
        stack<TreeNode *> s;
        if (nodes.size() % 2 == 0) {
            // 当前为奇数层，从左往右
            for (auto node: nodes[nodes.size() - 1]) {
                if (node->right != nullptr) s.push(node->right);
                if (node->left != nullptr) s.push(node->left);
            }

        } else {
            for (auto node: nodes[nodes.size() - 1]) {
                if (node->left != nullptr)s.push(node->left);
                if (node->right != nullptr) s.push(node->right);
            }
        }

        if (s.empty()) return;

        vector<TreeNode *> newLayer;
        while (!s.empty()) {
            newLayer.push_back(s.top());
            s.pop();
        }

        nodes.push_back(newLayer);
        run(nodes);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
}