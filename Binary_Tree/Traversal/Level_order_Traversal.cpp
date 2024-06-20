// Level order Traversal
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/5336327/simple-solution-in-c/

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    queue<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        vector<int> level;
        int size = st.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = st.front();
            st.pop();
            if (temp->left != NULL)
            {
                st.push(temp->left);
            }
            if (temp->right != NULL)
            {
                st.push(temp->right);
            }
            level.push_back(temp->val);
        }
        v.push_back(level);
    }
    return v;
}