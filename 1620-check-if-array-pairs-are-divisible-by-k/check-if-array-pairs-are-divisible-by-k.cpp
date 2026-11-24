class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int rem=((arr[i]%k)+k)%k;
            mp[rem]++;
        }
        for(int i=0;i<arr.size();i++){
            int rem=((arr[i]%k)+k)%k;
            int reqRem=k-rem;
            if(rem==0){
                if((mp[rem]&1)==0) continue;
                else return false;
            }
            if(mp.count(reqRem)){
                if(mp[rem]!=mp[reqRem]) return false;
            }
            else {
                return false;
            }
        }
        return true;
    }
};