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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        bool ans=1;
        queue<TreeNode*>pq;
        // initial state
        pq.push(root);
        int count=0;
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                auto front=pq.front(); pq.pop();
                if(!front){
                    // 1 null to allowed hai
                    count++;
                    continue;
                }
                if(front and count>=1){
                    // 1 null ke baad root aa gyi
                    return false;
                }
                pq.push(front->left);
                pq.push(front->right);
            }
        }
        return ans;
    }
};