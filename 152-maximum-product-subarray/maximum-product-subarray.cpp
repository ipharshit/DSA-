class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product=nums[0];
        int min_product=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            // at each index i have 2+1 choice here
            // include it to the previous ans
            int p1=max_product*nums[i];
            // treat it as the new ans
            int p2=nums[i];
            // 3: 2 smallest -ve numbers can result in larger product
            int p3=min_product*nums[i];
            max_product=max(p1,max(p3,p2));
            min_product=min(p3,min(p1,p2));
            ans=max(max_product,max(ans,min_product));
        }
        return ans;
    }
};