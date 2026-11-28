class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowels=0;
        int currVowels=0;
        // 1st window
        for(int i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') currVowels++;
        }
        maxVowels=currVowels;
        for(int i=k;i<s.size();i++){
            if(s[i-k]=='a' or s[i-k]=='e' or s[i-k]=='i' or s[i-k]=='o' or s[i-k]=='u') currVowels--;
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') currVowels++;
            maxVowels=max(maxVowels,currVowels);
        }
        return maxVowels;
    }
};