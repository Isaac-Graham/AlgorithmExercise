//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。 
//
// 你应当保留两个分区中每个节点的初始相对位置。 
//
// 示例: 
//
// 输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5
// 
// Related Topics 链表 双指针


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
    ListNode *partition(ListNode *head, int x) {
        ListNode *l1 = nullptr, *l2 = nullptr;
        ListNode *res = nullptr;
        ListNode *l2_head = nullptr;
        while (head != nullptr) {
            if (head->val < x) {
                if (l1 == nullptr) {
                    l1 = head;
                    res = l1;
                    head = head->next;
                } else {
                    l1->next = head;
                    l1 = l1->next;
                    head = head->next;
                }
                l1->next = nullptr;
            } else {
                if (l2 == nullptr) {
                    l2 = head;
                    l2_head = l2;
                    head = head->next;
                } else {
                    l2->next = head;
                    l2 = l2->next;
                    head = head->next;
                }
                l2->next = nullptr;
            }
        }
        if (l1 != nullptr) {
            l1->next = l2_head;
        }else{
            res = l2_head;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution *s = new Solution();
    vector<int> vec = {1};
    vector<ListNode *> v;
    for (int index = 0; index < vec.size(); index++) {
        v.push_back(new ListNode(vec[index]));
    }
    for (int i = 0; i < v.size() - 1; i++) {
        v[i]->next = v[i + 1];
    }
    ListNode *res = s->partition(v[0], 0);
    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}