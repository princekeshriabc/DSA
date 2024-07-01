// Two Sum In BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solutions/5395665/simple-solution-in-c/
// Time complexity = O(n)
// Space complexity = O(H)

class BSTIterator
{
    stack<TreeNode *> st;
    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isreverse)
    {
        reverse = isreverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        reverse ? pushAll(temp->left) : pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            if (reverse)
            {
                st.push(node);
                node = node->right;
            }
            else
            {
                st.push(node);
                node = node->left;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if ((i + j) == k)
                return true;
            else if ((i + j) > k)
            {
                j = r.next();
            }
            else
            {
                i = l.next();
            }
        }
        return false;
    }
};