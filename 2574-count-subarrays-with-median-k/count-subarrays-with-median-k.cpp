class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int medianIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                medianIndex=i;
                break;
            }
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int currSum=0;
        for(int i=medianIndex+1;i<nums.size();i++) {
            if(nums[i]>k) currSum++;
            else currSum--;
            mp[currSum]++; 
        }
        currSum=0;
        // we considered only [5]
        int ans=mp[0]+mp[1]; // considering [4] and [4,5] -> balance 0+1
        for(int i=medianIndex-1;i>=0;i--){
            if(nums[i]>k) currSum++;
            else currSum--;
            ans+=mp[-currSum];
            ans+=mp[1-currSum];
        }
        return ans; 
    }
};