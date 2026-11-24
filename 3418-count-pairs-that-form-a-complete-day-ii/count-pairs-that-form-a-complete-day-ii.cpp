class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<hours.size();i++) {
            int rem=((hours[i]%24)+24)%24;
            mp[rem]++;
        }
        for(int i=0;i<24;i++){
            int rem=i;
            int reqRem=24-rem;
            if(rem==0){
                ans+=((long long )mp[rem]*(mp[rem]-1))/2;
            }
            else if(mp.count(reqRem)){
                if(rem==reqRem) ans+=(mp[rem]*(mp[rem]-1))/2;
                else if(rem<reqRem) ans+=mp[rem]*mp[reqRem];
            }
        }
        return ans;
    }
};