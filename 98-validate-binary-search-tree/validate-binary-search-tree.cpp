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
void solve(TreeNode* root,vector<int>&inorder){
    if(!root) return ;
    // L
    solve(root->left,inorder);
    // N
    inorder.push_back(root->val);
    // R
    solve(root->right,inorder);
}
    bool isValidBST(TreeNode* root) {
        vector<int>inorder;
        solve(root,inorder);
        //  inorder of bst is always sorted
        // if its not sorted, it is not a bst
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]) return false;
        }
        return true;
    }
};