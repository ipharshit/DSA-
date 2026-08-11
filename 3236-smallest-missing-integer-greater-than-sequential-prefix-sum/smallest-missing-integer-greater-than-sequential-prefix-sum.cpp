class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        int prefix=nums[0];
        for(int i=1;i<nums.size();i++){
            // finding the longest prefix sum
            if(nums[i] == (nums[i - 1] + 1)) prefix+=nums[i];
            else break; 
        }
        // finding the smallest missing integer that is not in nums
        while(true){
            if(mp.find(prefix)!=mp.end()) prefix++;
            else return prefix;
        }
        return -1;
    }
};