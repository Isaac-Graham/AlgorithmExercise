//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。 
//
// 说明: 
//1 ≤ m ≤ n ≤ 链表长度。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL 
// Related Topics 链表


#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return head;
        }
        ListNode *res = head;
        int index = 1;
        while (index < m - 1) {
            index++;
            head = head->next;
        }
        ListNode *last_unchanged = head;
        ListNode *tail = head->next;
        ListNode *last = head;
        head = head->next;
        index++;
        while (index < n + 1) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = last;
            last = tmp;
            index++;
        }
        if (m != 1) {
            last_unchanged->next = last;
            tail->next = head;
            return res;
        } else {
            last_unchanged->next = head;
            return last;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void output(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void test(ListNode *head, int m, int n) {
    Solution *s = new Solution();
    ListNode *h = s->reverseBetween(head, m, n);
    output(h);
}

int main() {
    Solution *s = new Solution();
    vector<vector<int>> vec = {
            {1, 2, 3, 4, 5},
            {},
            {1},
            {1, 2, 3, 4, 5},
    };
    vector<vector<ListNode *>> v;
    for (int i = 0; i < vec.size(); i++) {
        vector<ListNode *> tmp;
        for (int j = 0; j < (int) vec[i].size(); j++) {
            tmp.push_back(new ListNode(vec[i][j]));
        }
        for (int i = 0; i < (int) tmp.size() - 1; i++) {
            tmp[i]->next = tmp[i + 1];
        }
        v.push_back(tmp);
    }
    test(v[0][0], 3, 4);
    test(v[2][0], 1, 1);
    test(v[3][0], 2, 4);
    cout << "end" << endl;
}