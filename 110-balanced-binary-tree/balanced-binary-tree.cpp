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
int solve(TreeNode* root,bool &ans,int height){
    if(!root) return 0;
    int leftHeight=solve(root->left,ans,height+1);
    int rightHeight=solve(root->right,ans,height+1);
    int diff=abs(leftHeight-rightHeight);
    if(diff>1) ans=false;
    return 1+(max(leftHeight,rightHeight)); 
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ans=true;
        solve(root,ans,0);
        return ans;
    }
};