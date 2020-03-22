//
// Created by Isaac Graham on 7/30/2019.
//

/**
 * 暴力就完事了
 */
#include <bits/stdc++.h>

using namespace std;


//  Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l = new ListNode(-1);
        ListNode *head = l;
        while (l1 != NULL && l2 != NULL) {
            l->next = l1->val < l2->val ? l1 : l2;
            l = l->next;
            (l1->val < l2->val ? l1 : l2) = ((l1->val < l2->val ? l1 : l2)->next);
        }
        while (l1 != NULL) {
            l->next = l1;
            l = l->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            cout << 5 << endl;
            l->next = l2;
            l = l->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    Solution *s = new Solution();
    ListNode *l = s->mergeTwoLists(l1, l2);
    while (l != NULL) {
        cout << (*l).val << endl;
        l = l->next;
    }
}