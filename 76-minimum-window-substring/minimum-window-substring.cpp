class Solution {
public:
    string minWindow(string s, string t) {
        int min_len=INT_MAX;
        int low=0;
        int high=0;
        int i=0;
        unordered_map<char,int>mp;
        for(auto ch:t) mp[ch]++;
        int missing=t.size();
        while(high<s.size()){
            // hire
            char ch=s[high];
            if(mp.find(ch)!=mp.end()){
                if(mp[ch]>0) missing--;
                mp[ch]--;
            }
            //while window is valid
            while(missing==0){
                // now window is valid
                // i have to find min
                if(min_len>high-low+1){
                    i=low;
                    min_len=high-low+1;
                }
                if(mp.find(s[low])!=mp.end()){
                mp[s[low]]++;
                if(mp[s[low]]>0) missing++;
            }
                // shrink
                low++;
            }
            high++;
        }
        string ans=s.substr(i,min_len);
        return min_len==INT_MAX?"":ans;
    }
};