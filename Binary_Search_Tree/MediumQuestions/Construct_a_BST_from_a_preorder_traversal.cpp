// Construct a BST from a preorder traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/solutions/5381802/simple-solution-in-c/
// time complexity = O(height of the tree)
// space complexity = O(height of the tree)

TreeNode *help(vector<int> &preorder, int &i, int bound)
{
    if (preorder.size() == i || preorder[i] > bound)
        return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = help(preorder, i, root->val);
    root->right = help(preorder, i, bound);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return help(preorder, i, INT_MAX);
}