class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int need[26]={0};
        int have[26]={0};
        string balloon="balloon";
        int ans=INT_MAX;
        for(int i=0;i<text.size();i++) have[text[i]-'a']++;
        for(int i=0;i<balloon.size();i++) need[balloon[i]-'a']++;
        for(int i=0;i<balloon.size();i++){
            ans=min(have[balloon[i]-'a']/need[balloon[i]-'a'],ans);
        }
        return ans;
    }
};