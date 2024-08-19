#include <bits/stdc++.h>
using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0; // Line 8: Suggest renaming 'count' to 'carry' for clarity
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        temp->next = new ListNode((sum + carry) % 10);
        carry = (sum + carry) / 10; // Line 15: Suggest adding a comment explaining carry calculation
        temp = temp->next;
    }
    return dummy->next;
}