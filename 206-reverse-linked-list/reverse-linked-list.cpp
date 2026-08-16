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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        auto temp=head;
        ListNode* prev=nullptr;
        auto forw=temp->next;
        while(temp){
            temp->next=prev;
            prev=temp;
            temp=forw;
            if(forw) forw=forw->next;
        }
        return prev;
    }
};