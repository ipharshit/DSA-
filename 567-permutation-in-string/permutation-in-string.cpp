class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>freq(26);
        for(int i=0;i<s1.size();i++) freq[s1[i]-'a']++;
        vector<int>f(26);
        //1 st wind
        int n=s1.size();
        for(int i=0;i<n;i++) f[s2[i]-'a']++;
        if(f==freq) return true;
        // remaining wind
        for(int i=n;i<s2.size();i++){
            f[s2[i-n]-'a']--;
            f[s2[i]-'a']++;
            if(f==freq) return true;
        }
        return false;
    }
};