// Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/solutions/5395593/simple-solution-in-c/
// time complexity =O(1)
// space complexity = O(h)

class BSTIterator
{
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void pushAll(TreeNode *node)
    {
        for (; node != NULL; st.push(node), node = node->left)
            ;
    }
};
