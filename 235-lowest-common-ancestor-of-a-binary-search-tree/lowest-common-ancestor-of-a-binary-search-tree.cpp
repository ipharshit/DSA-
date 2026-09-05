/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
int solve(TreeNode* root,TreeNode*p,TreeNode*q,TreeNode* &ans){
    if(!root) return 0;
    int leftAns=solve(root->left,p,q,ans);
    int rightAns=solve(root->right,p,q,ans);
    int self=0;
    if(root==p or root==q) self=1;
    self+=leftAns+rightAns;
    if(self==2 and ans==nullptr) ans=root;
    return self;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* ans=nullptr; 
        solve(root,p,q,ans);
        return ans;
    }
};