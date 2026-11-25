class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>count;
        int ans=0;
        int maxFreq=0;
        for(int i=0;i<nums.size();i++){
            int oldFreq=mp[nums[i]];
            mp[nums[i]]++;
            int newFreq=mp[nums[i]];
            if(oldFreq>0) count[oldFreq]--;
            count[newFreq]++;
            maxFreq=max(mp[nums[i]],maxFreq);
            int currPrefixLen=i+1;

            // i have the 3 cases:

            // case 1 -> all no. have same freq =1
            if(maxFreq==1) ans=i+1;

            // case 2 -> only 1 num have freq==1 and all other have same freq(maxFreq)
            else if(count[1]==1 and count[maxFreq]*maxFreq==currPrefixLen-1) ans=i+1;

            // case 3-> only 1 element have maxFreq and all others have maxFreq-1 
            else if(count[maxFreq]==1 and count[maxFreq-1]*(maxFreq-1)==currPrefixLen-maxFreq) ans=i+1; 

        }
        return ans;
    }
};