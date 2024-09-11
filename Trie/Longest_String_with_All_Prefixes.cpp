// Longest String with All Prefixes
// https://www.naukri.com/code360/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h>
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
    bool checkcomplete(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containkey(word[i]))
            {
                node = node->next(word[i]);
                if (node->isend() == false)
                    return false;
            }
            else
            {

                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }
    string longest = "";
    for (auto &it : a)
    {
        if (trie.checkcomplete(it) && longest.size() < it.size())
        {
            longest = it;
        }
        else if (trie.checkcomplete(it) && longest.size() == it.size() && it < longest)
        {
            longest = it;
        }
    }
    if (longest == "")
        return "None";
    return longest;
}