//
// Created by Isaac_Chen on 2020/1/12.
//
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

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        vector<ListNode *> vec;
        while (head != nullptr) {
            vec.push_back(head);
            head = head->next;
        }
        int length = vec.size();
        if (length == 0) {
            return head;
        } else if (k % length == 0) {
            return vec[0];
        }
        k = k % length;
        vec[length - 1]->next = vec[0];
        vec[length - k - 1]->next = NULL;
        return vec[length - k];
    }
};

int main() {
    vector<ListNode *> vec(3);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = new ListNode(i);
        if (i != 0) {
            vec[i - 1]->next = vec[i];
        }
    }
    Solution *s = new Solution();
    for (int i = 3; i <= 4; i++) {
        ListNode *head = s->rotateRight(vec[0], i);
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}
