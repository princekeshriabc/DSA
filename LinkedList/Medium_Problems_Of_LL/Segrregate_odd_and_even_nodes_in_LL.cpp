// Segrregate odd and even nodes in LL
// https://leetcode.com/problems/odd-even-linked-list/solutions/5316460/simple-solution-in-o-n-c/
// time complexity = O(n)
// space complexity = O(1)

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenhead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}