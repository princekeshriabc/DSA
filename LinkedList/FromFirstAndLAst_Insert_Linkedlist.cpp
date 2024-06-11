
// Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x)
{
    // Your code here
    Node *temp = new Node(x);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
    // Your code here
    Node *temp = new Node(x);
    Node *temp1 = head;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    while (temp1->next)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}