//
// Created by Isaac Graham on 7/31/2019.
//

/**
 * 用栈
 * O(n)遍历问题
 * 没啥可以注解的
 * 注意条件就好了
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode *> node_stack;
        ListNode *new_head = head;
        ListNode *p = head;
        bool meet = false;
        while (head != NULL) {
            node_stack.push(head);
//            cout << head->val << endl;
            head = head->next;
            if (node_stack.size() % k == 0) {
                if (!meet) {
                    meet = true;
                    new_head = node_stack.top();
                    p = new_head;
                    node_stack.pop();
                }
                while (!node_stack.empty()) {
                    p->next = node_stack.top();
                    node_stack.pop();
                    p = p->next;
                    p->next = head;
                }
            }
//            cout << head->val << endl;
        }
//        while (!node_stack.empty()) {
//            p->next = node_stack.top();
//            node_stack.pop();
//            p = p->next;
//        }
        return new_head;
    }
};

int main() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    Solution *s = new Solution();
    ListNode *head = s->reverseKGroup(l, 3);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}