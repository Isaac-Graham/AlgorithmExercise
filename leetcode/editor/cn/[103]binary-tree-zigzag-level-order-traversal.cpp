//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回锯齿形层次遍历如下： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索


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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<Item *> q;
        q.push(new Item(root, 0));
        int currentLevel = 0;
        vector<Item *> levelNodes;
        while (!q.empty()) {
            while (!q.empty() && q.front()->level == currentLevel) {
                Item *top = q.front();
                q.pop();
                levelNodes.push_back(top);
            }
            while (res.size() <= currentLevel) {
                vector<int> vec;
                res.push_back(vec);
            }
            if (currentLevel % 2 == 0) {
                for (int i = 0; i < levelNodes.size(); i++) {
                    res[currentLevel].push_back(levelNodes[i]->node->val);
                }
            } else {
                for (int i = levelNodes.size() - 1; i >= 0; i--) {
                    res[currentLevel].push_back(levelNodes[i]->node->val);
                }
            }

            for (auto top : levelNodes) {
                if (top->node->left != nullptr) {
                    q.push(new Item(top->node->left, top->level + 1));
                }
                if (top->node->right != nullptr) {
                    q.push(new Item(top->node->right, top->level + 1));
                }
            }
            levelNodes.clear();
            currentLevel++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    TreeNode *three = new TreeNode(3);
    TreeNode *nine = new TreeNode(9);
    TreeNode *twenty = new TreeNode(20);
    TreeNode *fifty = new TreeNode(15);
    TreeNode *seven = new TreeNode(7);
    three->left = nine;
    three->right = twenty;
    twenty->left = fifty;
    twenty->right = seven;
    vector<vector<int>> res = s->zigzagLevelOrder(three);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "end" << endl;
}