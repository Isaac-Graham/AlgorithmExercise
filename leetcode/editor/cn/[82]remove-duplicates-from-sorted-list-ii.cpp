//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
//
//
// 示例 2:
//
// 输入: 1->1->1->2->3
//输出: 2->3
// Related Topics 链表


#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *l1 = nullptr;
        ListNode *res = nullptr;
        ListNode *curr = head;
        head = head->next;
        while (head != nullptr) {
            bool duplicate = false;
            while (head != nullptr && head->val == curr->val) {
                duplicate = true;
                head = head->next;
            }
            if (!duplicate) {
                if (l1 == nullptr) {
                    l1 = curr;
                    res = l1;
                } else {
                    l1->next = curr;
                    l1 = l1->next;
                }

            } else {
                if (head == nullptr) {
                    if (l1 != nullptr) {
                        l1->next = nullptr;
                    }
                }
            }

            curr = head;
            if (head == nullptr) {
                break;
            } else if (head->next == nullptr) {
                if (l1 == nullptr) {
                    res = head;
                } else {
                    l1->next = head;
                }
                break;
            } else {
                head = head->next;
            }
        }
        return res;
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
        for (int integer : vec[i]) {
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