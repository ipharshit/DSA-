class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int low=0;
        int high=0;
        int ans=0;
        while(high<s.size()){
            // hire
            mp[s[high]]++;
            while(mp[s[high]]>2){
                // shrink/fire
                mp[s[low]]--;
                low++;
            }
            ans=max(high-low+1,ans);
            high++;
        }
        return ans;
    }
};