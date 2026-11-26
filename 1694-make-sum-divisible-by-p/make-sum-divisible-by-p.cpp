class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long int totalSum=accumulate(nums.begin(),nums.end(),0LL);
        int target=totalSum%p;  // yahi remove karna hai
        if(target==0) return 0;

        int ans=INT_MAX;
        long long int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int req=((currSum-target)%p+p)%p;
            if(mp.count(req)) ans=min(ans,i-mp[req]);
            int rem=currSum%p;
            mp[rem]=i;
        }
        return ans==nums.size()?-1:ans;
    }
};