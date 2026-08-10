class Solution {
public:

    bool solve(int n){
        if(n<=0 ){
            // losing condition 
            return false;
        }
        //i want alice to win 
        // means she should have a choice 
        // means i should select atleast 1 perfect square and give it to bob
        // if i don't have any perfect squares <n i loose
        bool ans=false;
        for(int i=1;i<=n;i++){
            if(i*i<=n) ans=ans||!solve(n-i*i);
        }
        return ans;
    }

    bool solve2(int n,vector<int>&dp){
        if(n<=0 ){
            // losing condition 
            return false;
        }
        //step 3
        if(dp[n]!=-1) return dp[n];
        //i want alice to win 
        // means she should have a choice 
        // means i should select atleast 1 perfect square and give it to bob
        // if i don't have any perfect squares <n i loose
        bool ans=false;
        for(int i=1;1LL*i*i<=n;i++){
            if(1LL*i*i<=n) ans=ans||!solve2(n-i*i,dp);
        }
        // step 2
        return dp[n]=ans;
    }


    bool winnerSquareGame(int n) {
        // return solve(n);

        // 1d dp
        vector<int>dp(n+1,-1);
        return solve2(n,dp);
    }
};