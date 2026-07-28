class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            char ch=s[i];
            mp[ch]++;
        }
        string left="",right="";
        string middle="";
        for(int i=0;i<n/2;i++){
            // first half
            left+=s[i];
        }
        sort(left.begin(),left.end());
        if(n&1){
            //odd
            middle=s[n/2];
        }
        right=left;
        reverse(right.begin(),right.end());
        ans+=left+middle+right;
        return ans;
    }
};