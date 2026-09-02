class Solution {
public:
void solve(vector<int>& candidates, int target,int i,int sum,vector<int>&temp,vector<vector<int>>&ans){
    // BC
    if(sum==target){
        ans.push_back(temp);
        return;
    }
    if(i==candidates.size()){
        return;
    }
    // i can select any no. on a given index
    for(int j=i;j<candidates.size();j++){
        int num=candidates[j];
        if(num+sum<=target){
            sum+=num;
            temp.push_back(num);
            solve(candidates,target,j,sum,temp,ans); // same no. again
            sum-=num;
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(candidates,target,i,sum,temp,ans);
        return ans;
    }
};