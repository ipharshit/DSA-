class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int maxlength=INT_MAX;
        int low=0;
        int high=0;
        long long sum=0;
        while(high<nums.size()){
            // pehle to hire karo
            sum+=nums[high];
            // check karo agar kaam ho raha hai
            while(sum>=target){
                int length=high-low+1;
                maxlength=min(length,maxlength);
                // firing start
                sum-=nums[low++];
            }
            // kaam hona band ho gyaa
            // fir se hire karo
            high++;
        }
        return maxlength==INT_MAX?0:maxlength;
    }
};