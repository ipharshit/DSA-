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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right or !head->next) return head;
        auto temp=head;
        ListNode* prev=nullptr;
        auto forw=temp->next;
        // first reach at the left position 
        for(int i=0;i<left-1;i++){
            prev=temp;
            temp=forw;
            forw=forw->next;
        }
        // yaha main first reverse krne vali node par aa gya
        auto before=prev;
        auto curr=temp;
        //reverse logic
        for(int i=0;i<right-left+1;i++){
            temp->next=prev;
            prev=temp;
            temp=forw;
            if(forw) forw=forw->next;
        }
        curr->next=temp;
        if(!before) return prev;
        before->next=prev;
        return head;
    }
};