/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Placeholder for intersection logic
        auto a=headA;
        auto b=headB;
        while(a!=b){
            a=(a==nullptr)?headB:a->next;
            b=(b==nullptr)?headA:b->next;
        }
        return b;
     
    }
};