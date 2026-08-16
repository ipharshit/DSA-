class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>mp;
        for(auto i:s) mp[i]++;
        int ans=0;
        bool oddFound=0;
        for(auto it:mp){
            char ch=it.first;
            int freq=it.second;
            if(freq==1){
                oddFound=1;
                continue;
            }
            else if(freq&1){
                // odd 
                oddFound=1;
                ans+=freq-1;
            }
            else{
                // even
                ans+=freq;
            }
        }
        return oddFound?ans+1:ans;
    }
};