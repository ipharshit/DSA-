class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxAverage=sum/k;
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            double currAverage=sum/k;
            maxAverage=max(maxAverage,currAverage);
        }
        return maxAverage;
    }
};