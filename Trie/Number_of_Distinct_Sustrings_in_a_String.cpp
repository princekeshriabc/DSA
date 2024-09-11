// Number of Distinct Substrings in a String
// https://www.naukri.com/code360/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h>
class Node
{
    Node *links[26];

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
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containkey(s[j]))
            {
                count++;
                node->set(s[j], new Node());
            }
            node = node->next(s[j]);
        }
    }
    return count + 1;
}