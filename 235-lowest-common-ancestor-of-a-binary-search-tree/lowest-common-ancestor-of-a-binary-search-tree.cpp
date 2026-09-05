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
    int rightAns;
    int leftAns;
    if(p->val>root->val and q->val>root->val){
        // both p and q exists in right part
        // no need to go left
        rightAns=solve(root->right,p,q,ans);
        leftAns=0;
    }
    else if(p->val<root->val and q->val<root->val){
        // both p and q exist in left part
        // no need to go right
        leftAns=solve(root->left,p,q,ans);
        rightAns=0;
    }
    else{
        // p and q are in diff parts
        ans=root;
    }
    
    return 0;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* ans=nullptr; 
        solve(root,p,q,ans);
        return ans;
    }
};