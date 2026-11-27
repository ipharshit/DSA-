class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        unordered_map<long long,unordered_map<long long,long long>>mp;
        mp[0][0]=1; 
        long long currSum=0;
        long long currVowels=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='o' or s[i]=='i' or s[i]=='u'){
                currSum++;
                currVowels++;
            }
            else currSum--;
            long long reqSum=currSum-0;
            if(mp.count(reqSum)){
               for(auto &[pastVowels,freq]:mp[reqSum]){
                    long long reqVowels=(currVowels%k)-pastVowels;
                    long long product=reqVowels*reqVowels;
                    if(product%k==0) ans+=freq;
               }
            }
            mp[currSum][currVowels%k]++;
        }
        return ans;
    }
};