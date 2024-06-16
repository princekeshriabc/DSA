// Given a singly linked list, delete middle of the linked list.
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/solutions/5321458/simple-solution-in-c-o-n/
// time complexity = O(n)
// space complexity = O(1)

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *fast = head;
    fast = fast->next->next;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete (temp);
    return head;
}