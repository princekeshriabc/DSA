// Inorder Successor/Predecessor in BST
// Time complexity = O(h)
// Space complexity = O(1)

#include <bits/stdc++.h>
using namespace std;
int inorder_successor(TreeNode* root,TreeNode* p){
    if(!root){
        return NULL;
    }
    TreeNode *temp=NULL;
    if(root->val<=p->val){
        root = root->right;
    }
    else{
        temp = root;
        root = root->left;
    }
    return temp->val;
}

int inorder_Predecessor(TreeNode *root, TreeNode *p)
{
    if (!root)
    {
        return NULL;
    }
    TreeNode *temp = NULL;
    if (root->val <= p->val)
    {
        temp = root;
        root = root->right;
    }
    else
    {
        root = root->left;
    }
    return temp->val;
}