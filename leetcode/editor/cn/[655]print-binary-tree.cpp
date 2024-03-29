//给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩
//阵需要遵循以下规则： 
//
// 
// 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。 
// 矩阵的列数 n 应该等于 2ʰᵉⁱᵍʰᵗ⁺¹ - 1 。 
// 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。 
// 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2ʰᵉⁱᵍʰᵗ⁻ʳ⁻¹] ，右子节点放置在 
//res[r+1][c+2ʰᵉⁱᵍʰᵗ⁻ʳ⁻¹] 。 
// 继续这一过程，直到树中的所有节点都妥善放置。 
// 任意空单元格都应该包含空字符串 "" 。 
// 
//
// 返回构造得到的矩阵 res 。 
//
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2]
//输出：
//[["","1",""],
// ["2","",""]]
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,3,null,4]
//输出：
//[["","","","1","","",""],
// ["","2","","","","3",""],
// ["","","4","","","",""]]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数在范围 [1, 2¹⁰] 内 
// -99 <= Node.val <= 99 
// 树的深度在范围 [1, 10] 内 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 136 👎 0

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int nodeNum = calcNodeNum(root, 0);

        vector<vector<string>> res( nodeNum, vector<string>(pow(2, nodeNum) - 1, ""));
        addVal(res, root, 0, 0,pow(2,nodeNum) - 1);
        return res;
    }

    int calcNodeNum (TreeNode * root, int curHeight) {
        if (root == nullptr) {
            return curHeight;
        }
        return max(calcNodeNum(root->left, curHeight + 1), calcNodeNum(root->right, curHeight + 1));
    }

    void addVal (vector<vector<string>> &vec,TreeNode * root, int row, int beginCol, int endCol) {
        if (row >= vec.size()) return;
        if (root == nullptr) return;
        int index =( beginCol +endCol) / 2;
        vec[row][index] = to_string(root->val) ;
        addVal(vec, root->left, row + 1, beginCol, index -1);
        addVal(vec, root->right, row+1, index + 1, endCol);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main () {
    Solution *s = new Solution();
    TreeNode*root = new TreeNode(1);
    TreeNode*node1 = new TreeNode(2);
    root->left = node1;
    s->printTree(root);
}