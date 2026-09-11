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
unordered_map<int,int>mp;
TreeNode* solve(vector<int>&postorder,int low,int high,int &i){
    if(i<0 or low>high){
        return NULL;
    }
    TreeNode* root=new TreeNode(postorder[i]);
    // find root in inorder
    int idx=mp[root->val];
    i--;
    root->right=solve(postorder,idx+1,high,i);
    root->left=solve(postorder,low,idx-1,i);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int low=0,high=inorder.size()-1,i=postorder.size()-1;
        return solve(postorder,low,high,i);
    }
};