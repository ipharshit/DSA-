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
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(char ch='a';ch<='z';ch++){
            if(mp.find(ch)!=mp.end()){
                if(mp[ch]&1){
                    // the freq is odd means it has left + 1 middle
                    int copy=mp[ch]/2;
                    while(copy--){
                        left+=ch;
                    }
                    //yaha tak left completed
                    middle+=ch;
                }
                else{
                    // even count means no middle
                    int copy=mp[ch]/2;
                     while(copy--){
                        left+=ch;
                    }
                }
            }
        }
        ans+=left+middle;
        reverse(left.begin(),left.end());
        ans+=left;
        return ans;
    }
};