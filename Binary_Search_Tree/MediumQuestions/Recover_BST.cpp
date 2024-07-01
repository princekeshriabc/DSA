// Recover BST
// https://leetcode.com/problems/recover-binary-search-tree/solutions/5395776/simple-solution-in-c/
// time complexity = O(n)
// spacecomplexity = O(1) not including the stack space

class Solution
{
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;

private:
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if ((prev->val > root->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};