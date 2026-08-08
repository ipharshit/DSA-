class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=nums[0];
        int normalMaxSum=nums[0];
        int minSum=nums[0];
        int currMin=nums[0];
        int currMax=nums[0];
        for(int i=1;i<nums.size();i++){
            currMax=max(nums[i],nums[i]+currMax);
            currMin=min(nums[i],nums[i]+currMin);
            totalSum+=nums[i];
            normalMaxSum=max(normalMaxSum,currMax);
            minSum=min(minSum,currMin);
        }
        int circularMaxSum=minSum==totalSum?normalMaxSum:totalSum-minSum;
        return max(circularMaxSum,normalMaxSum);
    }
};