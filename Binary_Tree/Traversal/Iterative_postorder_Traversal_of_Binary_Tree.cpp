// Iterative post order traversal using two stack and 1 stack
//  https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/5345715/simple-solution-by-iterative-method-using-2-stack-and-1-stack-both-approach/
//  Time complexity:   O(n)
//  Space complexity : O(n)

// Iterative solution using two stack
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> st1, st2;
    st1.push(root);
    if (root == NULL)
        return v;
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        root = st2.top();
        v.push_back(root->val);
        st2.pop();
    }
    return v;
}

// Iterative solution using 1 stack
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> st;
    if (root == NULL)
        return v;
    TreeNode *Curr = root;
    while (Curr != NULL || !st.empty())
    {
        if (Curr != NULL)
        {
            st.push(Curr);
            Curr = Curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                v.push_back(temp->val);
                st.pop();
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    v.push_back(temp->val);
                    st.pop();
                }
            }
            else
            {
                Curr = temp;
            }
        }
    }
    return v;
}