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
void solve(TreeNode* root,TreeNode* &prev,TreeNode* &firstSwap,TreeNode* &secondSwap,int &count){
    if(!root) return;
    solve(root->left,prev,firstSwap,secondSwap,count);
    if(prev){
        if(prev->val>=root->val){
            if(count==0){
                // yeh pehli mistake h
                firstSwap=prev;
                secondSwap=root;
            }
            else{
                // isse pehle bhi yeh mistake ho chuki hai
                secondSwap=root;
            }
            count++;
        }
    }
    prev=root;
    solve(root->right,prev,firstSwap,secondSwap,count);
}
    void recoverTree(TreeNode* root) {
        TreeNode* prev=0;
        TreeNode* firstSwap=0;
        TreeNode* secondSwap=0;
        int count=0;
        solve(root,prev,firstSwap,secondSwap,count);
        if(firstSwap and secondSwap){
            swap(firstSwap->val,secondSwap->val);
        }
    }
};