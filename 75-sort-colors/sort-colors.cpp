class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int k=nums.size()-1;
        while(j<=k){
            if(nums[j]==2){
                swap(nums[j],nums[k--]);
            }
            else if(nums[j]==0){
                swap(nums[j++],nums[i++]);
            }
            else j++;
        }
    }
};