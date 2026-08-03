class Solution {
public:
    int solve(vector<int>& stoneValue,int i){
        int n=stoneValue.size();
        // BC
        if(i>=n) return 0;
        // i have 3 choices
        // 1 stone
        int choice1=stoneValue[i]-solve(stoneValue,i+1);
        int choice2=INT_MIN,choice3=INT_MIN;
        //2 stone
        if(i+1<n) choice2=stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2);
        //3 stone
        if(i+2<n) choice3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3);
        return max(choice1,max(choice2,choice3));
    }

    int solve2(vector<int>& stoneValue,int i,vector<int>& dp){
        int n=stoneValue.size();
        // BC
        if(i>=n) return 0;
        //step3
        if(dp[i]!=-1) return dp[i];
        // i have 3 choices
        // 1 stone
        int choice1=stoneValue[i]-solve2(stoneValue,i+1,dp);
        int choice2=INT_MIN,choice3=INT_MIN;
        //2 stone
        if(i+1<n) choice2=stoneValue[i]+stoneValue[i+1]-solve2(stoneValue,i+2,dp);
        //3 stone
        if(i+2<n) choice3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve2(stoneValue,i+3,dp);
        //step2
        return dp[i]=max(choice1,max(choice2,choice3));
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // int diff=solve(stoneValue,0);
        vector<int>dp(stoneValue.size(),-1);
        int diff=solve2(stoneValue,0,dp);

        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};