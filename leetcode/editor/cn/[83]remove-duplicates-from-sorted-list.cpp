//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,1,2]
//输出：[1,2]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,1,2,3,3]
//输出：[1,2,3]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目在范围 [0, 300] 内 
// -100 <= Node.val <= 100 
// 题目数据保证链表已经按升序 排列 
// 
// Related Topics 链表 👍 719 👎 0


#include "Utils.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        if (head->next->val == head->val) {
            // duplicated
            head->next = head->next->next;
            return deleteDuplicates(head);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<vector<int>> vec = {
            {},
            {1, 1, 1, 1, 1, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 3, 4, 4, 4, 4, 4, 4, 4},
            {1, 2, 3, 3, 4, 4, 5},
            {1, 2},
            {1},
    };
    vector<vector<ListNode *>> v;
    for (int i = 0; i < vec.size(); i++) {
        vector<ListNode *> list;
        for (int integer: vec[i]) {
            list.push_back(new ListNode(integer));
        }
        for (int j = 0; j < (int) list.size() - 1; j++) {
            list[j]->next = list[j + 1];
        }
        v.push_back(list);
    }
    for (int i = 0; i < v.size(); i++) {
        ListNode *head;
        if (v[i].size() > 0)
            head = s->deleteDuplicates(v[i][0]);
        else
            head = nullptr;

        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}