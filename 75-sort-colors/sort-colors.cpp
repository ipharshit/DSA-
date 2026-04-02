class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=low,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                //isko topper mein bhejo
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                //nice
                mid++;
            }
            else{
                //2 ko backers mein bhejo
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};