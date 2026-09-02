class Solution {
public:
void solve(vector<int>& nums,int i,unordered_map<int,int>&mp,unordered_map<int,int>&currFreq,vector<int>&temp,vector<vector<int>>&ans){
    // BC
    if(i==nums.size()){
        // yaha parv mera ans ready h
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<nums.size();j++){
    int num =nums[j];
    // i can only add ch if 
    if(currFreq[num]<mp[num]){
        temp.push_back(num);
        currFreq[num]++;
        solve(nums,i+1,mp,currFreq,temp,ans);
        temp.pop_back();
        currFreq[num]--;
    }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        // store the freqa of each no:
        unordered_map<int,int>mp;
        unordered_map<int,int>currFreq;
        for(auto num:nums){
            mp[num]++;
            currFreq[num]=0;
        } 
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,0,mp,currFreq,temp,ans);
        return ans;
    }
};