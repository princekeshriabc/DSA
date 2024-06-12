// retun the middle node of the linkedlist
// Time Complexity: O(N)
// Space Complexity: O(1)
// tortoise and hare algorithm


ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}