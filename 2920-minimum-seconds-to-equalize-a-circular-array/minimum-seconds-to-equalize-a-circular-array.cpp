class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,int>prevIndex;
        unordered_map<int,int>currNumberAnswer;
        vector<int>arr=nums;
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
            prevIndex[nums[i]]=-1;
        } 
        for(int i=0;i<arr.size();i++){
            if(prevIndex[arr[i]]==-1){
                prevIndex[arr[i]]=i;
                continue;
            }
            else{
                // i have found the 2 elements 
                // they will both convert the elements on their left + right to themselves in 1 sec
                int prevIndexCurr=prevIndex[arr[i]];
                int totalElementsBetweenThem=i-prevIndexCurr-1;
                int totalSecondsToConvertThem=(totalElementsBetweenThem+1)/2;
                if(currNumberAnswer.count(arr[i])){
                    currNumberAnswer[arr[i]]=max(totalSecondsToConvertThem,currNumberAnswer[arr[i]]);
                }
                else{
                    currNumberAnswer[arr[i]]=totalSecondsToConvertThem;
                }
                prevIndex[arr[i]]=i;
            }
        }
        int ans=INT_MAX;
        for(auto curr:currNumberAnswer){
            ans=min(ans,curr.second);
        }
        return ans;
    }
};