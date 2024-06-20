// Binary Tree Representation in C++
// https://www.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

void help(node *root, vector<int> &vec, int idx)
{
    struct node *lc = newNode(vec[2 * idx + 1]);
    struct node *rc = newNode(vec[2 * idx + 2]);
    root->left = lc;
    root->right = rc;
    return;
}

void create_tree(node *root0, vector<int> &vec)
{
    // Your code goes here
    help(root0, vec, 0);
    help(root0->left, vec, 1);
    help(root0->right, vec, 2);
    return;
}