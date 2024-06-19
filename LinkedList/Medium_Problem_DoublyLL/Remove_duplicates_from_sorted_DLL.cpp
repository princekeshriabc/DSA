// Remove duplicates from sorted DLL
// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list
// time complexity = O(n)
// space complexity = O(1)

Node *removeDuplicates(struct Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextnode = temp->next;
        while (nextnode != NULL && temp->data == nextnode->data)
        {
            Node *dub = nextnode;
            nextnode = nextnode->next;
            delete dub;
        }
        temp->next = nextnode;
        if (nextnode)
            nextnode->prev = temp;
        temp = nextnode;
    }
    return head;
}