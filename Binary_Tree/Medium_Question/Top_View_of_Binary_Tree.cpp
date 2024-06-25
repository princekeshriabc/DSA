// Top View of Binary Tree
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Time Complexity = O(n)
// Space Complexity = O(n)

vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        Node *node = it.first;
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->data;
        }
        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}