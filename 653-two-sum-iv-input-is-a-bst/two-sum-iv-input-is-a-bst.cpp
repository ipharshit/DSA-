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
stack<TreeNode*>asc;
stack<TreeNode*>desc;
TreeNode* getSmall(){
    auto front=desc.top(); desc.pop();
    // yeh sabse badi value h
    auto leftChild=front->left;
    while(leftChild){
        desc.push(leftChild);
        leftChild=leftChild->right;
    }
    return front;
}
TreeNode* getLarge(){
        auto front=asc.top(); asc.pop();
        // yeh sabse choti value h
        auto rightChild=front->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild=rightChild->left;
        }
    return front;
}
    bool findTarget(TreeNode* root, int k) {
    // initial state
    auto t=root;
    while(root){
        asc.push(root);
        root=root->left;
    }
    // initial state
    root=t;
    while(root){
        desc.push(root);
        root=root->right;
    }
    auto low=getLarge();
    auto high=getSmall();
    while(low and high and low->val<high->val){
        int sum=low->val+high->val;
        if(sum==k) return true;
        else if(sum>k){
            // find smaller sum
            high=getSmall();
        }
        else if(sum<k){
            // find larger sum
            low=getLarge();
        }
    }
    return false;
    }
};