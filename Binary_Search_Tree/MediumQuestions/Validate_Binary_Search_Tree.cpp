// Validate Binary Search Tree

TreeNode *prev = NULL;
bool result = true;
void helper(TreeNode *root)
{
    if (root == NULL)
        return;
    helper(root->left);
    if (prev == NULL)
        prev = root;
    else if (root->val <= prev->val)
        result = false;
    else
        prev = root;
    helper(root->right);
}
bool isValidBST(TreeNode *root)
{
    helper(root);
    return result;
}