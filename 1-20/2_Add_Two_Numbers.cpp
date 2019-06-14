

#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        long long number1 = 0;
        while (l1 != NULL)
        {
            number1 *= 10;
            number1 += (*l1).val;
            l1 = (*l1).next;
        }
        long long number2 = 0;
        while (l2 != NULL)
        {
            number2 *= 10;
            number2 += (*l2).val;
            l2 = (*l2).next;
        }

        long long result = number1 + number2;
        ListNode *l = new ListNode(-1);
        ListNode *head = l;
        while (result != 0)
        {
            if (result >= 10)
            {
                ListNode *via = new ListNode(-1);
                (*l).next = via;
            }
            long long val = result % 10;
            (*l).val = val;
            result /= 10;
            l = (*l).next;
        }
        return head;
    }
};

int main()
{
    int length;
    scanf("%d", &length);
    int l1_val;
    scanf("%d", &l1_val);
    ListNode *l1 = new ListNode(l1_val);
    ListNode *head_l1 = l1;
    for (int index = 1; index < length; index++)
    {
        int l1_next_val;
        scanf("%d", &l1_next_val);
        l1->next = new ListNode(l1_next_val);
        l1 = l1->next;
    }
    scanf("%d", &length);
    int l2_val;
    scanf("%d", &l2_val);
    ListNode *l2 = new ListNode(l2_val);
    ListNode *head_l2 = l2;
    for (int index = 1; index < length; index++)
    {
        int l2_next_val;
        scanf("%d", &l2_next_val);
        l2->next = new ListNode(l2_next_val);
        l2 = l2->next;
    }

    Solution *s = new Solution();
    ListNode *l = (*s).addTwoNumbers(head_l1, head_l2);

    while (l->next != NULL)
    {
        printf("%d ", l->val);
        l = l->next;
    }
}