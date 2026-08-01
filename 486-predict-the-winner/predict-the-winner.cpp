    class Solution {
    public:
        // int solve(vector<int>&nums,int s,int e){
        //     if(s==e) return nums[s];
        //     // p1 starts the game
        //     int start=nums[s]-solve(nums,s+1,e);
        //     int end=nums[e]-solve(nums,s,e-1);
        //     return max(start,end);
        // }

        // int solve2(vector<int>&nums,int s,int e, vector<vector<int>>&dp){
        //     if(s==e) return nums[s];
        //     //step 3
        //     if(dp[s][e]!=-1) return dp[s][e];
        //     // p1 starts the game
        //     int start=nums[s]-solve2(nums,s+1,e,dp);
        //     int end=nums[e]-solve2(nums,s,e-1,dp);
        //     //step 2
        //     dp[s][e] = max(start,end);
        //     return max(start,end);
        // }

         int solve3(vector<int>&nums){
            //STEP 1
            vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
             //step 2
            for(int i=0;i<nums.size();i++) dp[i][i]=nums[i];
            //step3
            for(int s=nums.size()-1;s>=0;s--){
                for(int e=s+1;e<nums.size();e++){
                    int start=nums[s]-dp[s+1][e];
                    int end=nums[e]-dp[s][e-1];
                    dp[s][e] = max(start,end);
                }
            }
            return dp[0][nums.size()-1];
        }


        bool predictTheWinner(vector<int>& nums) {
            // return solve(nums,0,nums.size()-1)>=0;

            // // 2d dp
            // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
            // return solve2(nums,0,nums.size()-1,dp)>=0;

        return solve3(nums)>=0;

        }
    };