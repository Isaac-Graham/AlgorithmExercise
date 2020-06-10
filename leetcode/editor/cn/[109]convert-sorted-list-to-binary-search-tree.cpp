//给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 
//
// 示例: 
//
// 给定的有序链表： [-10, -3, 0, 5, 9],
//
//一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
// 
// Related Topics 深度优先搜索 链表


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void preOrder() {
        cout << val << " ";
        if (left != nullptr) {
            left->preOrder();
        }
        if (right != nullptr) {
            right->preOrder();
        }
    }

    void levelOrder() {
        struct Item {
            int level;
            TreeNode *node;

            Item(int level, TreeNode *node) : level(level), node(node) {}
        };
        queue<Item *> q;
        q.push(new Item(0, this));
        while (!q.empty()) {
            Item *top = q.front();
            q.pop();
            if (top->node != nullptr) {
                cout << top->node->val << " ";
                if (top->node->left != nullptr) {
                    q.push(new Item(top->level + 1, top->node->left));
                } else {
                    q.push(new Item(top->level + 1, nullptr));
                }
                if (top->node->right != nullptr) {
                    q.push(new Item(top->level + 1, top->node->right));
                } else {
                    q.push(new Item(top->level + 1, nullptr));
                }
            } else
                cout << "nullptr ";

        }
    }
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedVectorToBST(const vector<TreeNode *> &nodes, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        if (end == begin) {
            return nodes[begin];
        }
        int mid = (begin + end) / 2;
        TreeNode *root = nodes[mid];
        root->left = sortedVectorToBST(nodes, begin, mid - 1);
        root->right = sortedVectorToBST(nodes, mid + 1, end);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<TreeNode *> nodes;
        int length = 0;
        ListNode *newHead = head;
        while (newHead != nullptr) {
            length++;
            nodes.push_back(new TreeNode(newHead->val));
            newHead = newHead->next;
        }
        return sortedVectorToBST(nodes, 0, length - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *solution = new Solution();
    vector<int> vec = {-10, -3, 0, 5, 9};
    vector<ListNode *> nodes;
    for (int i = 0; i < vec.size(); i++) {
        nodes.push_back(new ListNode(vec[i]));
    }
    for (int i = 0; i < vec.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    TreeNode *root = solution->sortedListToBST(nodes[0]);
    root->levelOrder();
    cout << "end" << endl;
}