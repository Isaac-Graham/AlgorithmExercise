//
// Created by Isaac Graham on 7/31/2019.
//

/**
 * 递归
 * 注意swapPairs返回的是交换后的首指针
 * 这个信息可以用到
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        return p;
    }
};

int main() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    Solution *s = new Solution();
    ListNode *head = s->swapPairs(l);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

}