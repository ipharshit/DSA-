class Solution {
public:
    int minimumPushes(string word) {
        if(word.length()<=8) return word.length();
        int ans=0;
        for(int i=0;i<word.size();i++){
            ans+=i/8+1;
        }
        return ans;
    }
};