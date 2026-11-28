class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26);
        if(p.size()>s.size()) return {};
        int n=p.size();
        vector<int>ans;
        for(int i=0;i<n;i++) freq[p[i]-'a']++;
        vector<int>f(26);
        // process 1st window
        for(int i=0;i<n;i++) f[s[i]-'a']++;
        if(f==freq) ans.push_back(0);
        // process remaining windows
        for(int i=n;i<s.size();i++){
            f[s[i-n]-'a']--;
            f[s[i]-'a']++;
            if(f==freq) ans.push_back(i-n+1);
        }
        return ans;
    }
};