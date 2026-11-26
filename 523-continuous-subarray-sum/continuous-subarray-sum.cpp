class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int currSum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int reqSum=currSum%k;
            if(mp.count(reqSum)){
                int len=i-mp[reqSum];
                if(len>=2) return true;
            }
            else mp[reqSum]=i;
        }
        return false;
    }
};