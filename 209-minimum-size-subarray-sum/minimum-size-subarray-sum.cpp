class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int min_len=INT_MAX;
        int sum=0;
        while(high<nums.size()){
            // hire karo 
            sum+=nums[high];
            // check if kaam hone laga 
            while(sum>=target){
                // hone laga
                //fire
                int length=high-low+1;
                min_len=min(length,min_len);
                sum-=nums[low++];
            }
            high++;
        }
        return min_len==INT_MAX?0:min_len;
    }
};