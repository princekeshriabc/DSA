// Floor in BST
// https: // www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst
// Time complexity:O(h)
// Space complexity : O(1)

int floor(Node *root, int x)
{
    // Code here
    if (root == NULL)
        return -1;
    Node *node = root;
    int floor = -1;
    while (node != NULL)
    {
        if (node->data == x)
        {
            return x;
        }
        else if (node->data > x)
        {

            node = node->left;
        }
        else
        {
            floor = node->data;
            node = node->right;
        }
    }
    return floor;
}