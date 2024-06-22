// Maximum path sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/5350835/simple-solution-by-recursive-in-o-n/
// time complexity = O(n)
// space complexity = O(n)

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        heightcost(root, maxi);
        return maxi;
    }

private:
    int heightcost(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;
        int lsum = max(heightcost(root->left, maxi), 0);
        int rsum = max(heightcost(root->right, maxi), 0);
        maxi = max(maxi, (root->val + (lsum + rsum)));
        return (root->val) + max(lsum, rsum);
    }
};