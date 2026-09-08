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
void solve(TreeNode* root,int targetSum,int &sum,bool &ans){
    if(!root) return;
    sum+=root->val;
    if(!root->left and !root->right){
        // yeh leaf node hai
        if(targetSum==sum){
            ans=true;
        }
    }
    
    solve(root->left,targetSum,sum,ans);
    // backtrace
    if(!ans) solve(root->right,targetSum,sum,ans);
    sum-=root->val;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=false;
        solve(root,targetSum,sum,ans);
        return ans;
    }
};