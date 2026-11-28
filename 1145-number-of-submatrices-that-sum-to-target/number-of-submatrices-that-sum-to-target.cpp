class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<cols;i++){
            for(int j=i;j<cols;j++){
                int currSum=0;
                unordered_map<int,int>mp;
                mp[0]=1;
                for(int row=0;row<rows;row++){
                    currSum+=matrix[row][j]-(i>0?matrix[row][i-1]:0);
                    int reqSum=currSum-target;
                    ans+=mp[reqSum];
                    mp[currSum]++;
                }

            }
        }
        return ans;
    }
};