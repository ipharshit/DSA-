class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>st;
            int components=0;
            for(int j=i;j<nums.size();j++){
                if(!st.count(nums[j])){
                    components++;
                    if(st.count(nums[j]-1)) components--;
                    if(st.count(nums[j]+1)) components--;
                    st.insert(nums[j]);
                }
                ans+=components-1;
            }
            
        }
        return ans;
    }
};