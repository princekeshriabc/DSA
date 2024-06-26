// Delete a Node in Binary Search Tree
// https://leetcode.com/problems/delete-node-in-a-bst/solutions/5370903/simple-solution-in-c/
// Time complexity:O(h)
// Space complexity : O(1)

class Solution
{
public:
    TreeNode *last(TreeNode *root)
    {
        while (root->right == NULL)
        {
            return root;
        }
        return last(root->right);
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        TreeNode *rightnode = root->right;
        TreeNode *lastright = last(root->left);
        lastright->right = rightnode;
        return root->left;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *temp = root;
        while (root != NULL)
        {
            if (root->val > key)
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return temp;
    }
};