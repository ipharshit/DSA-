class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int low=0;
        int high=0;
        int ans=0;
        while(high<s.size()){
            //hire kro
            mp[s[high]]++;
            while(mp.find(s[high])!=mp.end() and mp[s[high]]>1){
                // fire
                mp[s[low]]--;
                low++;
            }
            // here i have all uniques
            ans=max(high-low+1,ans);
            high++;
        }
        return ans;
    }
};