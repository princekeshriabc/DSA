// Given a linked list, remove the n-th node from the end of list and return its head.

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/5321420/simple-solution-using-tortoise-and-hare-algo/
// time complexity = O(n)
// space complexity = O(1)

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *fast = head;
    while (n--)
    {
        fast = fast->next;
    }
    if (fast == NULL)
        return head->next;
    ListNode *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete (temp);
    return head;
}