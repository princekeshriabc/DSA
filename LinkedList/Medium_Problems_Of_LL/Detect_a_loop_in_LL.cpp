// Detect a loop in linkedlist
// https://leetcode.com/problems/linked-list-cycle/solutions/5300671/simple-solution-using-tortoise-hare-tc-o-n/
// Time Complexity = O(n)
// Space Complexity = O(1)

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}