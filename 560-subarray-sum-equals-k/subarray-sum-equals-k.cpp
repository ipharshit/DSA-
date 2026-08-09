class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int c=0;
        int currPrefix=0;
        for(int i=0;i<nums.size();i++){
            currPrefix+=nums[i];
            int prevPrefix=currPrefix-k;
            if(mp.find(prevPrefix)!=mp.end()) c+=mp[prevPrefix];
            mp[currPrefix]++;
        }
        return c;
    }
};