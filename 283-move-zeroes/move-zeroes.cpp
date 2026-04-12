class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
       int j=i+1;
       while(j<nums.size()){
        if(nums[i]!=0) i++;
        if(nums[j]!=0 and nums[i]==0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
       }
    }
};