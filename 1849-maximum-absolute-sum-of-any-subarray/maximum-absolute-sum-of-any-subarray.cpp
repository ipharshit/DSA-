class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size()==1) return abs(nums[0]);
        int ans=nums[0];
        int currMaxSum=nums[0];
        int currMinSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currMaxSum=max(nums[i],currMaxSum+nums[i]);
            currMinSum=min(nums[i],currMinSum+nums[i]);
            ans=max(ans,max(currMaxSum,abs(currMinSum)));
        }
        return ans;
    }
};