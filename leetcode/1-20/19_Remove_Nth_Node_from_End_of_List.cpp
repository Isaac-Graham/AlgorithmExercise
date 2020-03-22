//
// Created by Isaac Graham on 7/30/2019.
//

/**
 * 双指针思维，先让一个指针领先于另一个指针n步
 * 然后当领先的那个指针.next为空的时候就是到链表尾部的时候
 */

#include <bits/stdc++.h>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int step = 0; step < n; step++) {
            if (p2->next != NULL)
                p2 = p2->next;
            // 否则的话，说明n是大于等于链表的长度的，这个时候删除的只能是链表的头，所以直接返回head.next即可
            else {
                return head->next;
            }
        }
        while (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};
