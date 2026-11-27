class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        unordered_map<long long,unordered_map<long long,long long>>mp;
        int digitCount=0;
        int num=nums[0];
        while(num!=0){
            int digit=num%10;
            digitCount++;
            num/=10;
        }
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int digitPos=digitCount;
            while(num!=0){
                int digit=num%10;
                mp[digitPos][digit]++;
                digitPos--;
                num/=10;
            }
        }
        long long n=nums.size();
        long long totalPairs=n*(n-1)/2;
        long long ans=0;
        for(auto &m:mp){
            long long samePairs=0;
            for(auto &[digit,freq]:m.second){
                samePairs+=freq*(freq-1)/2;
            }
            long long diffPairs=totalPairs-samePairs;
            ans+=diffPairs;
        }
        return ans;
    }
};