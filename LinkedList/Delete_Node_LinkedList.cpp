// this function argument is given node 
// we have to delete that node from linked list
// this question on leetcode
// https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(ListNode *node)
{
    ListNode *temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete (temp);
}