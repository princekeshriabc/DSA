// Find pairs with given sum in DLL
// time complexity = O(n)
// space complexity = O(1)
// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    vector<pair<int, int>> v;
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left->data < right->data)
    {
        if (left->data + right->data == target)
        {
            v.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data > target)
        {
            right = right->prev;
        }
        else
        {
            left = left->next;
        }
    }
    return v;
}