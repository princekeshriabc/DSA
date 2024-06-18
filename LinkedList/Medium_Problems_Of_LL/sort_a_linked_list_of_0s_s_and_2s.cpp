// Function to sort a linked list of 0s, 1s and 2s.
// time complexity =O(n)
// space complexity = O(1)
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

Node *segregate(Node *head)
{

    // Add code here
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);
    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL;
    return zerohead->next;
}