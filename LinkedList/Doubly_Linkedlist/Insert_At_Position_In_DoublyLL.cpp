// insert a node at given position in to doubly linkedlist
// Time Complexity = O(pos)

void addNode(Node *head, int pos, int data)
{
    // Your code here
    if (head == NULL)
        return;
    if (pos == 0)
    {
        Node *newnode = new Node(data);
        newnode->next = head->next;
        if (head->next != NULL)
        {
            head->next->prev = newnode;
        }
        head->next = newnode;
        newnode->prev = head;
        return;
    }
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
        if (c == pos)
        {
            Node *newnode = new Node(data);
            newnode->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
            newnode->prev = temp;
            break;
        }
    }
    return;
}