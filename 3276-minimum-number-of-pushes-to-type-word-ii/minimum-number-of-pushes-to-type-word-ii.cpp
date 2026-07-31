class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        //store the frequencies
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            freq[ch-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            int freqCurrent=freq[i];
            ans+=freqCurrent*(i/8+1);
        }
        return ans;
    }
};