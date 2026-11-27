class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int reqSum=currSum-goal;
            ans+=mp[reqSum];
            mp[currSum]++;
        }
        return ans;
    }
};