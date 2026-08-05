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
// class Solution {
// public:
// int solve(ListNode* head){
//     auto temp=head;
//     int l=0;
//     while(temp) {
//         l++;
//         temp=temp->next;
//     }
//     return l;
// }
//     ListNode* middleNode(ListNode* head) {
//         int length=solve(head);
//         auto temp=head;
//         for(int i=1;i<=length/2;i++) temp=temp->next;
//         return temp;
//     }
// };

// method 2 -> slow and fast pointers

class Solution{
    public:
    ListNode* middleNode(ListNode* head) {
        auto slow=head;
        auto fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
