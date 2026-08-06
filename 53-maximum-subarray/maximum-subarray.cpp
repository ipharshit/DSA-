class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            // at each index 
            // i have 2 choices
            // include it with previous answer
            int choice1=nums[i]+sum;
            // treat it as the new ans
            int choice2=nums[i];
            sum=max(choice1,choice2);
            ans=max(ans,sum);
        }
        return ans;
    }
};