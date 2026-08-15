class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        unordered_map<int,int>mp;
        stack<int>st;
        // initial state
        st.push(nums2.back());
        mp[nums2.back()]=-1;
        for(int i=nums2.size()-2;i>=0;i--){
            int element=nums2[i];
            // find entry in stack which is greater than > element
            // agar koi chota mile to usko nikalo
            while(!st.empty() and st.top()<element){
                st.pop();
            } 
            // yaha aane ke 2 matlab hain
            // ya to stack empty ho gya ya usse bada element mil gya
            if(st.empty()){
                 st.push(element);
                 mp[element]=-1;
            }
            else{
                mp[element]=st.top();
                st.push(element);
            }
        }
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};