class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;int j=0;
        vector<int>ans;
        while(j<nums.size() and nums[j]<0){
            
            j++;
        }
        i=j-1;
        
        while(i>=0 and j<nums.size()){
            if(abs(nums[i])>=nums[j]){
                int sq=nums[j]*nums[j];
                ans.push_back(sq);
                j++;
            }
            else{
                int sq=nums[i]*nums[i];
                ans.push_back(sq);
                i--;
            }
        }
        //yaha tak aa gaya
        //matlab koi 1 array khali ho gya
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }
};