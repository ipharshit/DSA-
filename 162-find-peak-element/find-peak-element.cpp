class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+((e-s)>>1);
            if(nums[mid]>nums[mid+1]){
                // mid can be a answer
                // so cant ignore it
                e=mid;
            }
            else{
                // mid can't be my answer
                s=mid+1;
            }
        }
        return s;
    }
};