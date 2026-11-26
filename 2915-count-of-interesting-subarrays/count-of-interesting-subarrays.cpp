class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k) arr[i]=1;
            else arr[i]=0;
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        long long int c=0;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=arr[i];
            int reqSum=((currSum-k)%modulo+modulo)%modulo;
            c+=mp[reqSum];
            mp[currSum%modulo]++;
        }
        return c;
    }
};