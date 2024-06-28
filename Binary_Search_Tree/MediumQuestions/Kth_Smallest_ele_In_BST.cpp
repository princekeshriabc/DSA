// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/5381421/simple-solution-in-o-1-space-using-morris-traversal/
// time complexity =O(Height of the tree)
// space complexity =O(1)


// using Morris traversal this question asked in top company interview
int kthSmallest(TreeNode *root, int k)
{
    TreeNode *curr = root;
    int count = 0;
    while (curr != NULL)
    {
        TreeNode *pre = curr->left;
        if (pre == NULL)
        {
            count++;
            if (count == k)
            {
                return curr->val;
            }
            curr = curr->right;
        }
        else
        {
            while (pre->right != NULL)
            {
                pre = pre->right;
            }
            pre->right = curr;
            TreeNode *temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }
    }
    return -1;
}