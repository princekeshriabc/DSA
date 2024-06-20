// Iterative Preorder Traversal of Binary Tree
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/5336388/simple-solution-by-iterative-method-in-c/

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        v.push_back(root->val);
        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }
    return v;
}