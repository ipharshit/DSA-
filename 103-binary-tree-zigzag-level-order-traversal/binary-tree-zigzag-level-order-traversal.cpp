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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        // initial state
        q.push(root);
        bool direction=1; // left->right
        while(!q.empty()){
            int size=q.size();
            vector<int>temp(size);
            int s=0,e=temp.size()-1;
            while(size--){
                auto front=q.front(); q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                if(direction){
                    // left to right
                    temp[s]=front->val;
                    s++;
                }
                else{
                    // right to left
                    temp[e]=front->val;
                    e--;
                }
            }
            // yaha par mere paas 1 lvl complete ho gya 
            direction=!direction;
            ans.push_back(temp);
        }
        return ans;
    }
};