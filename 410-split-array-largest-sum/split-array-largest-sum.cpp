class Solution {
public:
bool canSplitWithCurrentSum(vector<int>& nums, int k,int mid){
    int currSum=0;
    int currSplit=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            // my guessed largest sum is less than the currSum
            return false;
        }
        else if(nums[i]+currSum<=mid){
            // i can take it
            currSum+=nums[i];
        }
        else{
            // i have to split it
            currSplit++;
            currSum=nums[i];
            if(currSplit>k) return false;
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        // define the search space
        // min sum of array -> single element
        int s=*min_element(nums.begin(),nums.end());
        // max sum of array-> whole arra sum
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(canSplitWithCurrentSum(nums,k,mid)){
                // i want to minimize the larget sum
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};