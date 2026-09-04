/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool solve(TreeNode* p,TreeNode* q){
    if(!p and !q) return true;
    if(!p or !q) return false;
    if(p->val!=q->val) return false;
    bool leftAns=solve(p->left,q->right);
    bool rightAns=solve(p->right,q->left);
    return leftAns and rightAns;

}
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->left,root->right);
    }
};