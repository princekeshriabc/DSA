// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/5381487/simple-solution-in-c/
// Time complexity =(height of the tree )
// Space complexity = O(n) this is stack space in recursion

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}