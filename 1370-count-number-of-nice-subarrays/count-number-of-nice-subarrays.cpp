class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) arr[i]=1;
            else arr[i]=0;
        } 
        unordered_map<int,int>mp;
        mp[0]=1;
        int c=0;
        int currSum=0;
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            int reqSum=currSum-k;
            c+=mp[reqSum];
            mp[currSum]++;
        }
        return c;
    }
};