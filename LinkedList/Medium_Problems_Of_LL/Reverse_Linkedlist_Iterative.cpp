// reverse a linked list using iterative method
// Time Complexity: O(n)
// Space Complexity: O(1)

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}