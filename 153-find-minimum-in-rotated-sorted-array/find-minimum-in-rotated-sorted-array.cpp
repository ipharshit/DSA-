class Solution {
public:
    int findMin(vector<int>& nums) {
        // rotated sorted array m jo min element hoga 
        // vo starting element se to bda hoga
        int s=0;
        int e=nums.size()-1;
        int start=nums[0];
        int ans=-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(nums[mid]<start){
                // m second half par hu
                // yeh answer ho bhi skta hai or nhi bhi
                ans=nums[mid];
                // move left to find minimum
                e=mid-1;
            }
            else{
                // m left part m hu
                // yaha to sab bade h 
                // move right
                s=mid+1;
            }
        }
        return ans==-1?nums[0]:ans;
    }
};