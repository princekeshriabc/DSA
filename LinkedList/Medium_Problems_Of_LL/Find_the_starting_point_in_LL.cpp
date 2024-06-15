// Find the starting point in LL
// time complexity = O(n)
// space complexity = O(1)
// https://leetcode.com/problems/linked-list-cycle-ii/solutions/5316226/simple-solution-by-tortoise-and-hare-algo-tc-o-n/

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    slow = head;
    while (fast != NULL)
    {
        if (slow == fast)
            return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}