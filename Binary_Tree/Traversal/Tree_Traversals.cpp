// https://www.naukri.com/code360/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    vector<int> inorder;
    vector<int> prerder;
    vector<int> postrder;
    stack<TreeNode *, int> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            prerder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it->right, 1});
            }
        }
        else
        {
            postrder.push_back(it.first->data);
        }
    }
    v.push_back(inorder);
    v.push_back(prerder);
    v.push_back(postrder);
    return v;
}