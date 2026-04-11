class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count=0;
        
        for(int k=nums.size()-2;k>=2;k--){
            unordered_map<int,int>mp;
            for(int l=k+1;l<nums.size();l++){
                int diff=nums[l]-nums[k];
                mp[diff]++;
            }
            //check if the sum exists in map
            for(int i=0;i<k;i++){
                for(int j=i+1;j<k;j++){
                    int sum=nums[i]+nums[j];
                    if(mp.find(sum)!=mp.end()){
                        count+=mp[sum];
                    }
                }
            }
        }
        return count;
    }
}; 