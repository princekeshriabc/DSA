// Postorder Traversal of Binary Tree by recursive
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/5336268/simple-solution-by-recursive-method-in-c/

void post(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    post(root->left, v);
    post(root->right, v);
    v.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> v;
    post(root, v);
    return v;
}