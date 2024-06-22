// find the diameter of given binary tree
// https://leetcode.com/problems/diameter-of-binary-tree/solutions/5350653/simple-solution-time-and-space-complexity-is-o-n/
// time complexity = O(N)
// space complexity = O(N)

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;
        int lheight = height(root->left, diameter);
        int rheight = height(root->right, diameter);
        diameter = max(diameter, (lheight + rheight));
        return 1 + max(lheight, rheight);
    }
};