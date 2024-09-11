// Implement Trie ll
// https://www.naukri.com/code360/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h>
class Node
{
    Node *links[26];
    int eow = 0;
    int cop = 0;

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
    void increseprefix()
    {
        cop++;
    }
    void incresedeow()
    {
        eow++;
    }
    int geteow()
    {
        return eow;
    }
    int getcop()
    {
        return cop;
    }
    void reducecop()
    {
        cop--;
    }
    void erase()
    {
        eow--;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                node->set(word[i], new Node());
            }
            node = node->next(word[i]);
            node->increseprefix();
        }
        node->incresedeow();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containkey(word[i]))
            {
                node = node->next(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->geteow();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containkey(word[i]))
            {
                node = node->next(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getcop();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containkey(word[i]))
            {
                node = node->next(word[i]);
                node->reducecop();
            }
            else
            {
                return;
            }
        }
        node->erase();
    }
};
