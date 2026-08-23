class Solution {
public:
    int hIndex(vector<int>& citations) {
        // define saerch space
        // i can have 0 papers that shoulkd have h citations
        int s=0;
        // i can atmost have n papers that can have atleast h citatations
        int e=citations.size()-1;
        int n=citations.size();
        int ans=0;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(citations[mid]>=n-mid){
                // i have enough papers from mid to end
                ans=n-mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};