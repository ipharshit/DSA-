class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int, int>mp;
       int currSum=0;
       int ans=0;
       mp[0]++;
       for(int i=0;i<nums.size() ;i++) {
           currSum+=nums[i];
            int rem = ((currSum % k) + k) % k;
           if(mp.find(rem)!=mp.end()) ans+=mp[rem];
           mp[rem]++;
       }
        return ans;
    }
};