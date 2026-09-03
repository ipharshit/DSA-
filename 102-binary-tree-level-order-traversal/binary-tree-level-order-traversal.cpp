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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        // initial state
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            while(size--){
                auto front=q.front(); q.pop();
                // push its left and right children -> if exixt
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                temp.push_back(front->val);
            }
            // yaha par mere pas 1 lvl complete ho gya
            ans.push_back(temp);
        }
        return ans;
    }
};