// Preorder Traversal of Binary Tree by recursive
// Time compexity = O(n)
// space compexity = O(height of tree)
// https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/5336388/simple-solution-by-iterative-method-in-c/

void pre(TreeNode* root,vector<int>& v){
    if(root==NULL) return;
    v.push_back(root->val);
    pre(root->left,v);
    pre(root->right,v);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    pre(root,v);
    return v;
}