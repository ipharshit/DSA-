#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       /* vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target) {
                    return {i,j};  
            }
        }
    }*/
    //create mapping
    unordered_map<int,int>mapping;
    for(int i=0;i<nums.size();i++){
         mapping[nums[i]]=i;
    }
    //finding if the second answer exists
    for(int i=0;i<nums.size();i++){
        int comp=target-nums[i];
        if(mapping.find(comp)!=mapping.end()){
            if(i!=mapping[comp]){
                return {i,mapping[comp]};
            }
        }
    }
   return {};
    }
};