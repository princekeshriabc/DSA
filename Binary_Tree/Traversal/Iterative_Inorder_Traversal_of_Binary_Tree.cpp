// Iterative Inorder Traversal of Binary Tree
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/5345330/simple-solution-by-iterative-method/

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    TreeNode *node = root;
    stack<TreeNode *> st;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }
    }

    return v;
}