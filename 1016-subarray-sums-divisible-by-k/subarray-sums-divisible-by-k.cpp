class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int c=0;
        int cSum=0;
        for(int i=0;i<nums.size();i++){
            cSum+=nums[i];
            int reqSum=((cSum%k)+k)%k;
            c+=mp[reqSum];
            mp[reqSum]++;
        }
        return c;
    }
};