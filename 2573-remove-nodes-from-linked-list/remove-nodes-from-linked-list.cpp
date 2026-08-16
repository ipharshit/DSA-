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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        auto temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        // yaha par mere pass stack ready hai
        int maxSeen=st.top();
        temp=new ListNode(st.top());
        st.pop();
        while(!st.empty()){
            if(st.top()>=maxSeen){
                // it will give the ans in reverse order
                // so i have to inserty in front
                auto newHead=new ListNode(st.top());
                newHead->next=temp;
                temp=newHead;
                maxSeen=st.top();
            }
            st.pop();
        }
        return temp;
    }
};