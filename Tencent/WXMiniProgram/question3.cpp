//
// Created by Isc on 2020/8/21.
//

#include <bits/stdc++.h>

using namespace std;
struct LinkNode {
    int val;
    struct LinkNode *next;
};

void remove(LinkNode *head) {
    LinkNode *storeHead = head;
    while (head != nullptr && head->next != nullptr) {
        if (head->next->val == head->val) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
    head = storeHead;
}