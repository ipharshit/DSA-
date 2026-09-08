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
void solve(TreeNode* root,int targetSum,int &sum,vector<int>&temp,vector<vector<int>>&ans){
    if(!root) return;
    sum+=root->val;
    temp.push_back(root->val);
    if(!root->left and !root->right){
        // it is a leaf node
        if(sum==targetSum) ans.push_back(temp);
    }
    solve(root->left,targetSum,sum,temp,ans);
    solve(root->right,targetSum,sum,temp,ans);
    // backtrace
    sum-=root->val;
    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(root,targetSum,sum,temp,ans);
        return ans;

    }
};