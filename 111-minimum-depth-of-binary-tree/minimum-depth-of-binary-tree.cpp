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
void solve(TreeNode* root,int &ans,int c){
    if(!root) return;
    solve(root->left,ans,c+1);
    if(!root->left and !root->right){
        // leaf
        ans=min(ans,c);
        c=1;
    }
    solve(root->right,ans,c+1);
}
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        solve(root,ans,1);
        return ans;
    }
};