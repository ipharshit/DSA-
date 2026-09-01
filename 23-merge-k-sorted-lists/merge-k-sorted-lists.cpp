/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class cmp{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val; // min heap
        }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        // push all starting nodes 
        for(auto list:lists){
           if(list) pq.push(list);
        }
        // find the smallest node
        ListNode* newNode=new ListNode(0); // node
        auto temp=newNode; // pointer
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            temp->next=top;
            temp=top;
            if(top->next) pq.push(top->next); // push the neext element
        }
        return !newNode?newNode:newNode->next;
    }
};