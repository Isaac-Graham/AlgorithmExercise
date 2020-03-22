//
// Created by Isaac Graham on 7/31/2019.
//


/**
 * 跟前面的21题类似，分治地处理每两个链表
 * 时间复杂度时Nlogk
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists, int begin, int end) {
        if (end >= begin) {
            if (end - begin == 0)
                return lists[begin];
            else if (end - begin == 1) {
                return mergeTwoLists(lists[begin], lists[end]);
            } else {
                int mid = (begin + end) / 2;
                ListNode *l1 = mergeKLists(lists, begin, mid);
                ListNode *l2 = mergeKLists(lists, mid + 1, end);
                return mergeTwoLists(l1, l2);
            }
        } else
            return NULL;
    }

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
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode *> v = {};
    Solution *s = new Solution();
    ListNode *l = s->mergeKLists(v);
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
}