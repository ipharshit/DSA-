class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        int ones=0;
        while(high<nums.size()){
            // hire 
            if(nums[high]==1) ones++;
            int window_size=high-low+1;
            while(window_size-ones>k){
                // i can't flip more than k 0s
                if(nums[low]==1 and ones>0) ones--;
                low++;
                window_size=high-low+1;
            }
            ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};