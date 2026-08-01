class Solution {
public:
    int solve(vector<int>&nums,int s,int e){
        if(s==e) return nums[s];
        // p1 starts the game
        int start=nums[s]-solve(nums,s+1,e);
        int end=nums[e]-solve(nums,s,e-1);
        return max(start,end);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1)>=0;
    }
};