// reverese a doubly linkedlist 
// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// time complexity = O(n)

Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    Node *tempprev = NULL;
    while (temp != NULL)
    {
        tempprev = temp->prev;
        temp->prev = temp->next;
        temp->next = tempprev;
        temp = temp->prev;
    }
    return tempprev->prev;
}