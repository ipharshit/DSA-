class Solution {
public:
    int search(vector<int>& nums, int target) {
        // isse pehle minimum in sorted rotated array kr chuka hu 
        // pura logic usme likha hua h
        int s=0;
        int e=nums.size()-1;
        int minimumIndex=-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<nums[0]){
                minimumIndex=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        // first half-> 0 to minimum-1
        // second half -> minimum elemenet index to n-1
        // aur dono halves sorted h
        if(minimumIndex==-1) minimumIndex=nums.size();
        if(target>=nums[0]){
            // first half
            int low=0;
            int high=minimumIndex-1;
            while(low<=high){
                int mid=low+((high-low)>>1);
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high=mid-1;
                else low=mid+1;
            }
        }
        else {
             // second half
            int low=minimumIndex;
            int high=nums.size()-1;
            while(low<=high){
                int mid=low+((high-low)>>1);
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};