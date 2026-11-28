class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26);
        if(p.size()>s.size()) return {};
        int n=p.size();
        vector<int>ans;
        for(int i=0;i<p.size();i++) freq[p[i]-'a']++;
        for(int i=0;i<s.size()-n+1;i++){
            vector<int>f(26);
            for(int j=i;j<i+p.size();j++){
                f[s[j]-'a']++;
            }
            if(f==freq) ans.push_back(i);
        }
        return ans;
    }
};