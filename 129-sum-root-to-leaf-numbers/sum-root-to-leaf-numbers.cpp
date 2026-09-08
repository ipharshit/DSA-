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
void solve(TreeNode* root,int &numbers,int &digit,int &currSum){
    if(!root) return;
    digit=digit*10+root->val;
    if(!root->left and !root->right){
        numbers+=digit;
    }
    solve(root->left,numbers,digit,currSum);
    solve(root->right,numbers,digit,currSum);
    // bactrace
    digit/=10;
}
    int sumNumbers(TreeNode* root) {
        int numbers=0;
        int digit=0;
        int currSum=0;
        solve(root,numbers,digit,currSum);
        return numbers;
    }
};