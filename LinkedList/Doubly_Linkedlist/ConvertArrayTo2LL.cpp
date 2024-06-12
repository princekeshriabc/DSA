// convert the array into doubly linkedlist

Node *constructDLL(vector<int> &arr)
{
    // code here
    Node *head = new Node(arr[0]);
    Node *temp1 = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
    return head;
}