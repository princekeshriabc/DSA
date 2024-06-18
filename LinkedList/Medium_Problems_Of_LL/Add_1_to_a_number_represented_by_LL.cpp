// Add 1 to a number represented by LL
// time complexity = O(n)
// space complexity = O(n) this is of stack space
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

int helper(Node *temp)
{
    if (temp == NULL)
        return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}