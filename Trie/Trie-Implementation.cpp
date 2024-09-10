// Trie Implementation
// https://leetcode.com/problems/implement-trie-prefix-tree/solutions/5765433/simple-implementation-of-trie-in-c-striver-solution/
// Time Complexity = O(len(word))

class Node
{
    Node *links[26];
    bool eow = false;

public:
    bool containkey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void set(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *next(char ch)
    {
        return links[ch - 'a'];
    }
    void setend()
    {
        eow = true;
    }
    bool isend()
    {
        return eow;
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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                node->set(word[i], new Node());
            }
            node = node->next(word[i]);
        }
        node->setend();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                return false;
            }
            node = node->next(word[i]);
        }
        return node->isend();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containkey(prefix[i]))
            {
                return false;
            }
            node = node->next(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */