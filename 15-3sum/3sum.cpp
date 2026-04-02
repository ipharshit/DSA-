#include<vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int k=0;k<nums.size();k++){
             if(k>0 and nums[k]==nums[k-1]) continue;
            int i=k+1;
            int j=nums.size()-1;
            while(i<j){
                int sum=nums[i]+nums[j];
                if(sum==-nums[k]){ ans.push_back({nums[k],nums[i],nums[j]});
                i++;
                j--;
                       while(i<j and nums[i]==nums[i-1]) i++;
       while(j>i and nums[j]==nums[j+1]) j--;
            }
            else if(sum>-nums[k]) j--;
            else i++;
        }
    }
    return ans;
    }
};