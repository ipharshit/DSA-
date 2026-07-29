class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=INT_MAX;
        int min_diff=INT_MAX;
        // jiska target se abs diff jitna kam hoga 
        // vo target ke utna hi pass hoga
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            // if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(nums[i]+nums[j]+nums[k]==target){
                    return nums[i]+nums[j]+nums[k];
                }
                else if(sum<target) j++;
                else k--;
                if(min_diff>abs(target-sum)){
                        ans=sum;
                        min_diff=abs(target-sum);
                }
            }
        }
        return ans;
    }
};