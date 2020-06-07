//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
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
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索


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
struct Item {
    TreeNode *node;
    int level;

    Item(TreeNode *node, int level) : node(node), level(level) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<Item *> q;
        q.push(new Item(root, 0));
        while (!q.empty()) {
            Item *top = q.front();
            q.pop();
            while (res.size() <= top->level) {
                vector<int> vec;
                res.push_back(vec);
            }
            res[top->level].push_back(top->node->val);
            if (top->node->left != nullptr) {
                q.push(new Item(top->node->left, top->level + 1));
            }
            if (top->node->right != nullptr) {
                q.push(new Item(top->node->right, top->level + 1));
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
//    [3,9,20,null,null,15,7],
    TreeNode *three = new TreeNode(3);
    TreeNode *nine = new TreeNode(9);
    TreeNode *twenty = new TreeNode(20);
    TreeNode *fifty = new TreeNode(15);
    TreeNode *seven = new TreeNode(7);
    three->left = nine;
    three->right = twenty;
    twenty->left = fifty;
    twenty->right = seven;
    vector<vector<int>> res = s->levelOrder(three);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "end" << endl;
}