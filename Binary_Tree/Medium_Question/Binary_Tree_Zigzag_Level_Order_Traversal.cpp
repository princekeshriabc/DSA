// Binary Tree Zigzag Level Order Traversal
// time complexity = O(N)
// space complexity = O(N)
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/5360395/simple-solution-in-o-n/

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    queue<TreeNode *> q;
    q.push(root);
    bool LToR = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node1 = q.front();
            q.pop();
            int y = LToR ? i : (size - 1 - i);
            row[y] = node1->val;
            if (node1->left != NULL)
            {
                q.push(node1->left);
            }
            if (node1->right != NULL)
            {
                q.push(node1->right);
            }
        }
        LToR = !LToR;
        v.push_back(row);
    }
    return v;
}