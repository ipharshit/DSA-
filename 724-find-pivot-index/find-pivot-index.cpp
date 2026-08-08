// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>prefix(n);
//         vector<int>suffix(n);
//         prefix[0]=0;
//         suffix[n-1]=0;
//         for(int i=1;i<nums.size();i++){
//             prefix[i]=prefix[i-1]+nums[i-1];
//         }
//         for(int i=n-2;i>=0;i--){
//             suffix[i]=suffix[i+1]+nums[i+1];
//         }
//         for(int i=0;i<nums.size();i++){
//             if(prefix[i]==suffix[i]) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total-nums[0]==0) return 0;
        for(int i=1;i<nums.size();i++){
            left+=nums[i-1];
            int right=total-left-nums[i];
            if(left==right) return i;
        }
        return -1;
    }
};