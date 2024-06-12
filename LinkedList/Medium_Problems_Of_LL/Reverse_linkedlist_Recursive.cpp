// reverse a linked list using recursive method
// Time Complexity: O(n)
// Space Complexity: O(1)
// using tortoise and hare algo

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *newhead = reverseList(head->next);
    ListNode *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return newhead;
}