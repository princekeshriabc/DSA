// Time complexity = O(n)

Node *constructLL(vector<int> &arr)
{
    // code here
    Node *temp = new Node(arr[0]);
    Node *head = temp;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp1 = new Node(arr[i]);
        temp->next = temp1;
        temp = temp->next;
    }
    return head;
}