// Right/Left View of Binary Tree
// Given a binary tree, return the right/left view of the tree. The right/left view consists of all nodes that are visible when the tree is viewed from the right/left side.
// https://leetcode.com/problems/binary-tree-right-side-view/solutions/5364850/simple-solution-using-recursion-in-c/
// Time Complexity = O(n)
// Time Complexity = O(Height of the tree) = O(H)

// Right side View
void help(vector<int> &ans, int level, TreeNode *root)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->val);
    }
    help(ans, level + 1, root->right);
    help(ans, level + 1, root->left);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    help(ans, 0, root);
    return ans;
}

// Left side View
void help(vector<int> &ans, int level, TreeNode *root)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->val);
    }
    help(ans, level + 1, root->left);
    help(ans, level + 1, root->right);
}
vector<int> leftSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    help(ans, 0, root);
    return ans;
}
