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
void solve(TreeNode* root,vector<int>&numbers,int &digit,int &currSum){
    if(!root) return;
    currSum+=root->val;
    digit=digit*10+root->val;
    if(!root->left and !root->right){
        numbers.push_back(digit);
    }
    solve(root->left,numbers,digit,currSum);
    solve(root->right,numbers,digit,currSum);
    // bactrace
    digit/=10;
}
    int sumNumbers(TreeNode* root) {
        vector<int>numbers;
        int digit=0;
        int sum=0;
        int currSum;
        solve(root,numbers,digit,currSum);
        for(auto number:numbers){
            sum+=number;
        }
        return sum;
    }
};