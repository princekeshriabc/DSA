// Delete node in Doubly Linked List
// https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
// time complexity =O(n)

Node *deleteNode(Node *head, int x)
{
    // Your code here
    if (head == NULL)
        return head;
    if (x == 1)
    {
        head = head->next;
        head->prev = NULL;
        return head;
    }
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
        if (count == x)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            delete temp;
            break;
        }
    }
    return head;
}