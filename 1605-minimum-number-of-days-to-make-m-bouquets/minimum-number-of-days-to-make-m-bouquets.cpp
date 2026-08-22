class Solution {
public:
bool canMakeMBouquets(vector<int>&nums,int mid,int m,int k){
    // i have to check if i can make m bouquets on this day
    int currDay=mid;
    int countBouquetsOnCurrDay=0;
    // bool adjacent = false;
    int flower=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            // i cant take this flower
            flower=0;
        }
        if(nums[i]<=currDay){
            // i can take these flowers on today
            flower++;
            if(flower==k){
                // i made a bouquet
                countBouquetsOnCurrDay++;
                flower=0;
            }
        }
    }
    return countBouquetsOnCurrDay>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        // koi bhio flower ho vo min day vale din to aa hi jayega
        // aur koi bhi flower max day k baad to aa nahi skata
        // so our search space is
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(canMakeMBouquets(bloomDay,mid,m,k)){
                // i can make m bouquets on this day 
                // m isse jyada din bhi m bouquets bana hio luga 
                // because agle din aur bhi flowers aate jayege
                ans=mid;
                e=mid-1;
            }
            else{
                // agar m aaj bhi nhi bna paaya-> to aaj se pehle kabhi bana hi nahi pauga
                // because pichle dino m to kuch phool aaye bhi nahi honge
                s=mid+1; // aaj nhi bna paaya -> that's why not store ans
            }
        }
        return ans;
    }
};