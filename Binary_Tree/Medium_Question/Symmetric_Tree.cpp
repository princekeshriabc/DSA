// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// https://leetcode.com/problems/symmetric-tree/solutions/5364936/simple-solution-using-recursion-no-extra-space-only-stack-pace-in-c/
// Time Complexity: O(N)
// Space Complexity: O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree

bool help(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    return (root1->val == root2->val) && (help(root1->left, root2->right) && help(root1->right, root2->left));
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return help(root->left, root->right);
}