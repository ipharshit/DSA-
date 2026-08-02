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
    bool stoneGame(vector<int>& piles) {
        // return solve(piles,0,piles.size()-1)>0;
        //step 1
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        return solve2(piles,0,piles.size()-1,dp)>0;

    }
};