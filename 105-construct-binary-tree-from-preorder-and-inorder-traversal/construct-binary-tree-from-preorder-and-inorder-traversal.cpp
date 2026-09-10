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
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int low,int high,int &i){
    if(i>=preorder.size() or low>high){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[i]);
    // find root in inorder
    int idx=mp[root->val];
    i++;
    root->left=solve(preorder,inorder,low,idx-1,i);
    root->right=solve(preorder,inorder,idx+1,high,i);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int low=0,high=inorder.size()-1,i=0;
        return solve(preorder,inorder,low,high,i);
    }
};