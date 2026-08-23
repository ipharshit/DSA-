class Solution {
public:
bool canPublishHPapers(vector<int>&nums,int mid){
    int countPapers=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=mid){
            // i can publish this research papers-> i have enough citations
            countPapers++;
        }
    }
    return countPapers>=mid;
}
    int hIndex(vector<int>& citations) {
        // define saerch space
        // i can have 0 papers that shoulkd have h citations
        int s=0;
        // i can atmost have n papers that can have atleast h citatations
        int e=citations.size();
        int ans=-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(canPublishHPapers(citations,mid)){
                // i have enough papers that have atleast h citations
                ans=mid;
                // atleast yani-> apne phele valo se jyada
                s=mid+1;
            }
            else{
                // i do not have enough papers that have atleast h citations
                // the bar hi high
                e=mid-1;
            }
        }
        return ans;
    }
};