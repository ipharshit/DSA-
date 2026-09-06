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
    int kthSmallest(TreeNode* root, int k) {
        auto t=root;
        priority_queue<TreeNode*>pq;
        priority_queue<int>qp;
        // initial state
        pq.push(root);
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                auto front=pq.top(); pq.pop();
                if(front->left) pq.push(front->left);
                if(front->right) pq.push(front->right);
                if(qp.size()<k) qp.push(front->val);
                else{
                    if(front->val<qp.top()){
                        qp.pop();
                        qp.push(front->val);
                    }
                }
            }
        }
        return qp.top();
    }
};