class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=2;
        int j=2;
        if(nums.size()==1) return 1;
        while(j<nums.size()){
            if(nums[i-2]!=nums[j]) {
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};