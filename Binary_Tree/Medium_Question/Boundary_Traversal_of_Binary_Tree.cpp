// time complexity = O(N)
// space complexity = O(N)

#include <bits/stdc++.h>
using namespace std;

void lefttr(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (!isleaf(curr))
            res.push_back(curr->val);
        if (curr->left != NULL)
        {
            curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void leaftr(TreeNode *root, vector<int> &res)
{
    if (isleaf(root))
    {
        res.push_back(root->val);
        return;
    }
    if (root->left != NULL)
    {
        leaftr(root->left, res);
    }
    if (root->right != NULL)
    {
        leaftr(root->right, res);
    }
}
void righttr(TreeNode *root, vector<int> &res)
{
    vector<int> v;
    TreeNode *curr = root->right;
    while(curr!=NULL){
        if(!isleaf(curr)) {
            v.push_back(curr->val);
        }
        if(curr->right!=NULL){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        res.push_back(v[i]);
    }
    return;
}

vector<int> Boundary_Traversal(treeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isleaf(root))
        res.push_back(root->val);
    lefttr(root, res);
    leaftr(root, res);
    righttr(root, res);
    return res;
}