// Find the intersection point of a Linked List
// https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/5330901/simple-solution-tc-o-n-sc-o-1/
// time complexity = O(n)
// space complexity = O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    if (headA == NULL || headB == NULL)
        return NULL;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = headB;
        if (temp2 == NULL)
            temp2 = headA;
    }
    return temp1;
}