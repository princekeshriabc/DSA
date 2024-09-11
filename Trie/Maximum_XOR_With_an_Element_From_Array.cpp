// Maximum XOR With an Element From Array
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/solutions/5769854/simple-solution-using-trie-striver-approach/
// Time complexity:O(q(log(q))+(q∗32+n∗32)) // q=queries.size()
// n = nums.size()

class Node
{
    Node *links[2];

public:
    bool containkey(int bit)
    {
        return links[bit] != NULL;
    }
    void set(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *next(int bit)
    {
        return links[bit];
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (!node->containkey(bit))
            {
                node->set(bit, new Node());
            }
            node = node->next(bit);
        }
    }
    int getmax(int n)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (!node->containkey(1 - bit))
            {
                node = node->next(bit);
            }
            else
            {
                maxi = maxi | (1 << i);
                node = node->next(1 - bit);
            }
        }
        return maxi;
    }
};
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size(), 0);
        Trie trie;
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> q;
        for (int i = 0; i < queries.size(); i++)
        {
            q.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(q.begin(), q.end());
        int ind = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int mi = q[i].first;
            int xi = q[i].second.first;
            int qi = q[i].second.second;
            while (ind < nums.size() && nums[ind] <= mi)
            {
                trie.insert(nums[ind]);
                ind++;
            }
            if (ind == 0)
                ans[qi] = -1;
            else
                ans[qi] = trie.getmax(xi);
        }
        return ans;
    }
};