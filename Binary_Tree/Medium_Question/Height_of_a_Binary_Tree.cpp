// Given a binary tree, find its height.
// https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/5350363/simple-solution-by-recursive/

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lHeight = maxDepth(root->left);
    int rHeight = maxDepth(root->right);
    return 1 + max(lHeight, rHeight);
}