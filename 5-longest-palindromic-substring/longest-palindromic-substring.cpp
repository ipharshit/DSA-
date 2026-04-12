class Solution {
public:
    string longestPalindrome(string s) {
        string longest="";
        string str="";
        for(int k=0;k<s.size();k++){
            int n=s.size();
                int i=k;
                int j=k;
                while(i>=0 and j<s.size() and s[i]==s[j]){
                        i--;
                        j++;
                     str=s.substr(i+1,j-i-1);
                }
                    if(str.length()>=longest.size()) longest=str;
                 i=k;
                 j=k+1;
                while(i>=0 and j<s.size() and s[i]==s[j]){
                        i--;
                        j++;
                     str=s.substr(i+1,j-i-1);
                }
                    if(str.length()>=longest.size()) longest=str;
                }
        return longest;
    }
};