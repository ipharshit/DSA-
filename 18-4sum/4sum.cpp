class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long sum=(long long)target-((long long)nums[i]+nums[j]);
                int a=j+1;
                int b=nums.size()-1;
                while(a<b){
                    if((long long)nums[a]+nums[b]==sum){ 
                        //check further
                         ans.push_back({nums[i],nums[j],nums[a],nums[b]});
                         //move further
                         a++;
                         b--;
                         //skip duplicates first
                         while(a<b and nums[a]==nums[a-1]) a++;
                         while(b>a and nums[b]==nums[b+1]) b--;
                    }
                    else if((long long)nums[a]+nums[b]>sum){
                        //move left
                        b--;
                    }
                    else if((long long)nums[a]+nums[b]<sum){
                        //move right
                        a++;
                    }
                }
            }
        }
        return ans;
    }
};