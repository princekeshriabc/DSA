// Vertical Order Traversal of Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/5360760/simple-soltion-in-c-map-queue/
// Time complexity:O(N∗log2N∗log2N∗log2N)
// Space complexity : O(n)

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        TreeNode *temp = node.first;
        int x = node.second.first;
        int y = node.second.second;
        mp[x][y].insert(temp->val);
        if (temp->left != NULL)
        {
            q.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> v;
    for (auto it : mp)
    {
        vector<int> col;
        for (auto c : it.second)
        {
            col.insert(col.end(), c.second.begin(), c.second.end());
        }
        v.push_back(col);
    }
    return v;
}