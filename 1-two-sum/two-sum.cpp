class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(nums[i]+nums[j]==target) return {i,j};
    //         }
    //     }
    //     return {};
    // }
     
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]=i;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         int t=(target-nums[i]);
    //         // if(i==mp[t]) continue;
    //         if(mp.find(t)!=mp.end()&&i!=mp[t]) return {i,mp[t]};
    //     }
    //     return {};
    // }

     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int comp=target-nums[i];
            if(mp.find(comp)!=mp.end()) return {i,mp[comp]};
            mp[nums[i]]=i;

        }
        
        return {};
    }
};