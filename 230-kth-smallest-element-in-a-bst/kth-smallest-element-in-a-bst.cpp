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
        stack<TreeNode*>st;
        auto t=root;
        while(t){
            st.push(t);
            t=t->left;
        }
        while(!st.empty()){
            auto front=st.top(); st.pop();
            k--;
            if(k==0) return front->val;
            auto rightChild=front->right;
            while(rightChild){
                st.push(rightChild);
                rightChild=rightChild->left;
            }
        }
        return 0;
    }
};