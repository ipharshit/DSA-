class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1; // strting m to sum 0 hi hoga
        int currSum=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int reqSum=currSum-k;
            c+=mp[reqSum];
            mp[currSum]++;
        }
        return c;
    }
};