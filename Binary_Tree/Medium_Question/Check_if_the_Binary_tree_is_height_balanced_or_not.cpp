// Check if the Binary tree is height-balanced or not
// https://leetcode.com/problems/balanced-binary-tree/solutions/5350433/simple-solution-using-recursion/
// time complexity = O(n)
// space complexity = O(n)

int solve(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = solve(root->left);
    if (left == -1)
        return -1;
    int right = solve(root->right);
    if (right == -1)
        return -1;
    if (abs(right - left) > 1)
        return -1;
    return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
    if (solve(root) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}