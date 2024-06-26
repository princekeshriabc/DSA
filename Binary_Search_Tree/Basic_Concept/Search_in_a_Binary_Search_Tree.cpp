// Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/solutions/5365967/simple-solution-in-c/
// Time complexity:O(n)
// Space complexity : O(1) 


TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {

        if (root->val > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}