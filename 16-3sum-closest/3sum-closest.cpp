class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff=INT_MAX;
        int closest=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++){
            int i=k+1;
            int j=nums.size()-1;
            while(i<j){
                long long sum=(long long)nums[i]+nums[j]+nums[k];
                long long diff=llabs((long long)target-sum);
              
                if(diff<mindiff){
                    mindiff=diff;
                    closest=sum;
                } 
                if(sum>target) j--;
                else if(sum<target) i++;
                else if(sum==target) return sum;           
            }

        }
        return closest;
    }
};