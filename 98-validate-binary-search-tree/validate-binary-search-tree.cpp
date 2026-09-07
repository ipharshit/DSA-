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
bool solve(TreeNode* root,TreeNode* &prev){
    if(!root) return true;
    bool leftAns=solve(root->left,prev);
    if(prev){
        if(root->val<=prev->val) return false;
    }
    prev=root;
    bool rightAns=solve(root->right,prev);
    return leftAns && rightAns;
}
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return solve(root,prev);
    }
};