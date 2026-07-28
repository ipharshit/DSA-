// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         string ans="";
//         int n=s.size();
//         string left="",right="";
//         string middle="";
//         for(int i=0;i<n/2;i++){
//             // first half
//             left+=s[i];
//         }
//         sort(left.begin(),left.end());
//         if(n&1){
//             //odd
//             middle=s[n/2];
//         }
//         right=left;
//         reverse(right.begin(),right.end());
//         ans+=left+middle+right;
//         return ans;
//     }
// };

class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        string left="",middle="";
        vector<int>mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        for(char ch='a';ch<='z';ch++){
                if(mp[ch-'a']&1){
                    // 1 middle
                    //yaha tak left completed
                    middle+=ch;
                }
                int copy=mp[ch-'a']/2;
                    while(copy--){
                        left+=ch;
                    }
        }
        ans+=left+middle;
        reverse(left.begin(),left.end());
        ans+=left;
        return ans;
    }
};