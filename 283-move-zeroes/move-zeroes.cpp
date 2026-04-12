class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
       int j=i;
       while(j<nums.size()){
        if(nums[j]!=0 ){
            //place it 
            nums[i]=nums[j];
            i++;
        }
        j++;
       }
        for(int a=i;a<nums.size();a++) nums[a]=0; 
    }
};