class Solution {
public:
int solve(vector<int>&piles,int i,int M,bool aliceTurn){
    if(i>=piles.size()) return 0;
    int ans=aliceTurn?INT_MIN:INT_MAX;
    int curr_sum=0;
    // alice plays fist
    for(int x=1;x<=2*M;x++){
       if(i+x<=piles.size()) curr_sum+=piles[i+x-1];
        // i want to find the max stones that alice can get
        // so the difference idea won't work
        if(aliceTurn){
            // alice ki turn -> i want max
             ans=max(ans,curr_sum+solve(piles,i+x,max(x,M),false));
        }
        else{
            // bob ki turn
            ans=min(ans,solve(piles,i+x,max(x,M),true));
        }
    }
    return ans;
}

    int solve2(vector<int>& piles,int i,int M,bool aliceTurn,vector<vector<vector<int>>>&dp){
        if(i>=piles.size()) return 0;
        //step 3
        if(dp[i][M][aliceTurn]!=-1) return dp[i][M][aliceTurn];
    int ans=aliceTurn?INT_MIN:INT_MAX;
    int curr_sum=0;
    // alice plays fist
    for(int x=1; i+x <= piles.size() and x<=2*M;x++){
        curr_sum+=piles[i+x-1];
        // i want to find the max stones that alice can get
        // so the difference idea won't work
        if(aliceTurn){
            // alice ki turn -> i want max
             ans=max(ans,curr_sum+solve2(piles,i+x,max(x,M),false,dp));
        }
        else{
            // bob ki turn
            ans=min(ans,solve2(piles,i+x,max(x,M),true,dp));
        }
    }
    //step 2
    return dp[i][M][aliceTurn]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        // return solve(piles,0,1,true);

        // 3d dp
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return solve2(piles,0,1,true,dp);
    }
};