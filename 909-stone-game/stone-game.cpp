class Solution {
public:
// int solve(vector<int>& piles,int s,int e){
//     // BC
//     if(s==e) return piles[e];
//     // alice starts first
//     // we want A-B>0
//     int start=piles[s]-solve(piles,s+1,e);
//     int end=piles[e]-solve(piles,s,e-1);
//     return max(start,end);
// }

int solve2(vector<int>& piles,int s,int e,vector<vector<int>>&dp){
    // BC
    if(s==e) return piles[e];
    //step 3
    if(dp[s][e]!=-1) return dp[s][e];
    // alice starts first
    // we want A-B>0
    int start=piles[s]-solve2(piles,s+1,e,dp);
    int end=piles[e]-solve2(piles,s,e-1,dp);
    //step 2
    return dp[s][e]=max(start,end);
}


    int solve3(vector<int>&piles){
        //step 1
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),0));
        //step 2
        for(int i=0;i<piles.size();i++) dp[i][i]=piles[i];
        //step 3
        for(int s=piles.size()-1;s>=0;s--){
            for(int e=s+1;e<piles.size();e++){
                //copy paste
                // alice starts first
            // we want A-B>0
            int start=piles[s]-dp[s+1][e];
            int end=piles[e]-dp[s][e-1];
                dp[s][e]=max(start,end);
            }
        }
        return dp[0][piles.size()-1];
    }


    bool stoneGame(vector<int>& piles) {
        // return solve(piles,0,piles.size()-1)>0;
        //step 1
        // vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        // return solve2(piles,0,piles.size()-1,dp)>0;

        return solve3(piles)>0;
    }
};