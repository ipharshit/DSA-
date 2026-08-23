class Solution {
public:
bool canGiveEnoughCandies(vector<int> &candies,long long mid,long long k){
    long long countChildren=0;
    for(int i=0;i<candies.size();i++){
        if(candies[i]<mid){
            // i cant give these candies to even 1 child
            continue;
        }
        else{
            // i have enough candies
            long long divideCandies=candies[i]/mid;
            countChildren+=divideCandies;
        }
    }
    return countChildren>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        // define the saerch space
        // children can recieve min. candies
        long long s=1;
        long long e=*max_element(candies.begin(),candies.end());
        long long ans=0;
        while(s<=e){
           long long mid=s+((e-s)>>1);
           if(mid==0) return ans;
            if(canGiveEnoughCandies(candies,mid,k)){
                // i can give enough candies to the children
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};