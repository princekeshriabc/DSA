// https://leetcode.com/problems/palindrome-linked-list/solutions/5316386/simple-solution-in-o-n-tortoise-and-hare-algo/
// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
// time complexity = O(n)
// space complexity = O(1)

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
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newhead = reverseList(slow->next);
    ListNode *temp = newhead;
    ListNode *temp1 = slow;
    slow = head;
    while (newhead != NULL)
    {
        if (slow->val == newhead->val)
        {
            slow = slow->next;
            newhead = newhead->next;
        }
        else
        {
            reverseList(temp);
            return false;
        }
    }
    reverseList(temp);
    return true;
}