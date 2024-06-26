// find the min in binary search tree
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
// Time complexity:O(h)
// Space complexity : O(1)

int minValue(Node *root)
{
    // Code here
    int val = -1;
    while (root != NULL)
    {
        val = root->data;
        root = root->left;
    }
    return val;
}