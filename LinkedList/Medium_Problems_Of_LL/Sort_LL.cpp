// sort linked list
// https://leetcode.com/problems/sort-list/solutions/5330747/simple-solution-easy-to-understand-c-sc-o-1/
// Time complexity = O(n log(n))
// space complexity = O(1)

ListNode *findMiddle(ListNode *head)
{
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    if (l1)
        temp->next = l1;
    else
        temp->next = l2;
    return dummy->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *middle = findMiddle(head);
    ListNode *left = head;
    ListNode *right = middle->next;
    middle->next = NULL;
    ListNode *lefthead = sortList(left);
    ListNode *righthead = sortList(right);
    return merge(lefthead, righthead);
}