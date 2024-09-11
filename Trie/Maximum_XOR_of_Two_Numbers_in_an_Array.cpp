// Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/solutions/5769659/simple-solution-using-trie-striver-approach/
// Time complexity:O(n∗32+n∗32) == O(n)

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
            if (node->containkey(1 - bit))
            {
                maxi = maxi | (1 << i);
                node = node->next(1 - bit);
            }
            else
            {
                node = node->next(bit);
            }
        }
        return maxi;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int ans = 0;
        Trie trie;
        for (auto &it : nums)
        {
            trie.insert(it);
        }
        for (int &it : nums)
        {
            ans = max(ans, trie.getmax(it));
        }
        return ans;
    }
};