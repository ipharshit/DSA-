class Solution {
public:
    int maxCalculate(vector<int>v){
        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++) maxi=max(maxi,v[i]);
        return maxi;
    }
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int low=0;
        int high=0;
        int max_len=0;
        while(high<s.size()){
            // hire kro
            char ch=s[high];
            v[ch-'A']++;
            int max_freq=maxCalculate(v);
            int window_size=high-low+1;
            // fire kro
            while(window_size-max_freq>k){
                // changes needed are > k
                // can't do it
                char ch=s[low];
                v[ch-'A']--;
                low++;
                 max_freq=maxCalculate(v);
                window_size=high-low+1;
            }
            // yaha aa gaya matlab 
            // changes <= k
            // yeh kar sakte hain
            max_len=max(window_size,max_len);
            high++;
        }
        return max_len;
    }
};