// inorder Traversal of Binary Tree by recursive
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/5336251/simple-solution-by-recursive-method-in-c/

void inor(TreeNode* root,vector<int>& v){
    if(root==NULL) return ;
    inor(root->left,v);
    v.push_back(root->val);
    inor(root->right,v);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    inor(root,v);
    return v;
}