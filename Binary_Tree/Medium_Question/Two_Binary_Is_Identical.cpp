// Check if two trees are identical or not
// https://leetcode.com/problems/same-tree/solutions/5360279/simple-solution-using-recursion/
// time complexity = O(N)
// space complexity = O(N)

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}