class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>st;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
            st.insert(nums[i]);
        }
        // i have range [mini,maxi]
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};