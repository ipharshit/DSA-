class Solution {
public:
    int removeElement(vector<int>& nums, int value) {
        int i=0;
        int j=0;
        while(i<nums.size()){
            if(nums[i]!=value){
                nums[j++]=nums[i++];
            }
            else{
                i++;
            }
        }
        return j;
    }
};