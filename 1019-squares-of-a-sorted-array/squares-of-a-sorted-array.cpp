class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        vector<int>ans;
        vector<int>less;
        vector<int>greater;
        while(i<nums.size()){
            if(nums[i]<0){
            less.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
            }
            i++;
        }
        i=0;int j=0;
        reverse(less.begin(),less.end());
        
        while(i<less.size() and  j<greater.size()){
            if(abs(less[i])>greater[j]){
                int sq=greater[j]*greater[j];
                ans.push_back(sq);
                j++;
            }
            else{
                int sq=less[i]*less[i];
                ans.push_back(sq);
                i++;
            }
        }
        //yaha tak aa gaya
        //matlab koi 1 array khali ho gya
        while(i<less.size()){
            ans.push_back(less[i]*less[i]);
            i++;
        }
        while(j<greater.size()){
            ans.push_back(greater[j]*greater[j]);
            j++;
        }
        return ans;
    }
};