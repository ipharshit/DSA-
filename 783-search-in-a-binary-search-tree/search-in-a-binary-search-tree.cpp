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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val==val) return root;
        TreeNode* ans;
        if(root->val<val){
            // search in right
            ans=searchBST(root->right,val);
        }
        else{
            // search in left
            ans=searchBST(root->left,val);
        }
        return ans;
    }
};