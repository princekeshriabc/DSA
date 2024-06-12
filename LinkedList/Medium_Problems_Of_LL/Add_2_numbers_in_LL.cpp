// given two number as linkedlist form  and construct one liskedlist for the sum of two number;
// https://leetcode.com/problems/add-two-numbers/solutions/5298475/easy-to-understand-o-n-solution-add-two-number/
// Time complexity = O(n)

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    int sum = 0, carry = 0;
    ;
    while (temp1 != NULL || temp2 != NULL)
    {
        sum = carry;
        if (temp1)
            sum += temp1->val;
        if (temp2)
            sum += temp2->val;
        ListNode *curr1 = new ListNode(sum % 10);
        carry = sum / 10;
        curr->next = curr1;
        curr = curr->next;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        ListNode *curr1 = new ListNode(carry);
        curr->next = curr1;
    }
    return dummy->next;
}