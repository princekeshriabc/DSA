// Ceil in BST
// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// Time complexity:O(h) 
// Space complexity : O(1)

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    Node *node = root;
    int ceil = -1;
    while (node != NULL)
    {
        if (node->data == input)
        {
            return input;
        }
        else if (node->data > input)
        {
            ceil = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return ceil;
    // Your code here
}