//给定一个二叉树 
//
// struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//} 
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。 
//
// 初始状态下，所有 next 指针都被设置为 NULL。 
//
// 
//
// 进阶： 
//
// 
// 你只能使用常量级额外空间。 
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。 
// 
//
// 
//
// 示例： 
//
// 
//
// 输入：root = [1,2,3,4,5,null,7]
//输出：[1,#,2,3,#,4,5,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。 
//
// 
//
// 提示： 
//
// 
// 树中的节点数小于 6000 
// -100 <= node.val <= 100 
// 
//
// 
//
// 
// 
// Related Topics 树 深度优先搜索


#include <bits/stdc++.h>
#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        struct Item {
            int level;
            Node *node;

            Item(int level, Node *node) : level(level), node(node) {}
        };
        queue<Item *> q;
        q.push(new Item(0, root));
        while (!q.empty()) {
            int level = q.front()->level;
            vector<Item *> items;
            while (!q.empty() &&
                   level == q.front()->level) {
                items.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < items.size(); i++) {
                items[i]->node->next = i != items.size() - 1 ? items[i + 1]->node : nullptr;
                if (items[i]->node->left != nullptr) {
                    q.push(new Item(level + 1, items[i]->node->left));
                }
                if (items[i]->node->right != nullptr) {
                    q.push(new Item(level + 1, items[i]->node->right));
                }
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    
    cout << "end" << endl;
}