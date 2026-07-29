
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>>v;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(i>0 and nums[i-1]==nums[i]) continue;
//             for(int j=i+1;j<nums.size();j++){
//                 if(j>i+1 and nums[j-1]==nums[j]) continue;
//                 for(int k=j+1;k<nums.size();k++){
//                     if(k>j+1 and nums[k-1]==nums[k]) continue;
//                     if(nums[i] + nums[j] + nums[k] == 0) v.push_back({nums[i], nums[j], nums[k]});
//                 }
//             }
//         }
//         return v;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            if(i>0 and nums[i]==nums[i-1]) continue;
            int target=0-nums[i];
            while(j<k){
                if(nums[j]+nums[k]==target){
                    v.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }
                else if(nums[j]+nums[k]<target) j++;
                else k--;
            }
        }
        return v;
    }
};