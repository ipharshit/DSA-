class Solution {
public:
bool canLoadsPackages(vector<int>& weights, int days,int mid){
    int currDays=1;
    int currWeight=0;
    for(int i=0;i<weights.size();i++){
        if(mid<weights[i]){
            // ship[ weight is less than the curr package
            return false;
        }
        else if(weights[i]+currWeight>mid){
            // // icant take this package today
            // will take it tomorrow 
            // increase days
            currDays++;
            currWeight=weights[i];
            if(currDays>days) return false;
        }
        else{
            // currWeight<mid
            // load it
            currWeight+=weights[i];
        }
    }
    return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // define the search space
        // min wt of ship-> itna to hoga hi ki vo sabse jyada vala packet le ja ske'
        // tabhui to saare packets khtm ho paayege
        int s=*max_element(weights.begin(),weights.end());
        // max-wt of the ship-> sare packets le jaye 
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(canLoadsPackages(weights,days,mid)){
                ans=mid;
                // i want to find the min wt
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};