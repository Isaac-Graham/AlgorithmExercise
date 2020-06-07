//给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。 
//
// 
//
// 示例： 
//
// 输入：3
//输出：
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释：
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 8
// 
// Related Topics 树 动态规划


#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *>();
        }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int begin, int end) {
        vector<TreeNode *> trees;
        if (begin > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = begin; i <= end; ++i) {
            vector<TreeNode *> left = generateTrees(begin, i - 1);
            vector<TreeNode *> right = generateTrees(i + 1, end);

            for (auto leftNode : left) {
                for (auto rightNode : right) {
                    TreeNode *current = new TreeNode(i);
                    current->left = leftNode;
                    current->right = rightNode;
                    trees.push_back(current);
                }
            }
        }
        return trees;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
//    cout << "end" << endl;
}