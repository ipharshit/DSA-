class Solution {
public:
void mergeSort(vector<int>&nums,int s,int e,long long &ans){
    if(s>=e) return;
    int mid=s+((e-s)>>1);
    mergeSort(nums,s,mid,ans);
    mergeSort(nums,mid+1,e,ans);
    merge(nums,s,e,mid,ans);
}
void merge(vector<int>&nums,int s,int e,int mid,long long &ans){
    int l1=mid-s+1;
    int l2=e-mid;
    vector<int>left(l1);
    vector<int>right(l2);
    int mainArrayIndex=s;
    for(int i=0;i<l1;i++){
        left[i]=nums[mainArrayIndex++];
    }
    for(int i=0;i<l2;i++){
        right[i]=nums[mainArrayIndex++];
    }
    int i=0;
    int j=0;
    long long int goodPairs=0;
    mainArrayIndex=s;
    while(i<l1 and j<l2){
        if(left[i]<right[j]) i++;
        else if(left[i]>right[j]) j++;
        else{
            int same=left[i];
            int leftSameElements=0;
            int rightSameElements=0;
            while(i<l1 and left[i]==same){
                i++;
                leftSameElements++;
            } 
            while(j<l2 and right[j]==same){
                j++;
                rightSameElements++;
            }
            goodPairs+=1LL*leftSameElements*rightSameElements;
        }
    }
    long long totalPairs=1LL*l1*l2;
    long long badPairs=totalPairs-goodPairs;
    ans+=badPairs;
    i=0;
    j=0;
    mainArrayIndex=s;
    while(i<l1 and j<l2){
        // if(left[i]!=right[j]) 
        if(left[i]<right[j]){
            nums[mainArrayIndex++]=left[i++];
        }
        else{
            nums[mainArrayIndex++]=right[j++];
        }
    }
    while(i<l1) nums[mainArrayIndex++]=left[i++];
    while(j<l2) nums[mainArrayIndex++]=right[j++];
}
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        vector<int>arr(nums.size());
        for(int i=0;i<arr.size();i++){
            arr[i]=i-nums[i];
        }
        mergeSort(arr,0,nums.size()-1,ans);
        return ans;
    }
};