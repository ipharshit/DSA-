class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalElements=nums1.size()+nums2.size();
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int s=0;
        int e=nums1.size();
        while(s<=e){
            // put the wall in nums1
            int mid=s+((e-s)>>1);
            // .....mid-1|wall|mid......
            int left1,right1,left2,right2;
            if(mid==0) left1=INT_MIN;
            else left1=nums1[mid-1];
            if(mid==nums1.size()) right1=INT_MAX;
            else right1=nums1[mid];
            int elementsUsedInNums1=mid;    // nums1 ke left half mein total elements
            int elementsrequiredInNums1left=(totalElements+1)/2;
            int elementsRequiredFromNums2=elementsrequiredInNums1left-mid;
            if(elementsRequiredFromNums2>0) left2=nums2[elementsRequiredFromNums2-1];
            else left2=INT_MIN;
            if(elementsRequiredFromNums2<nums2.size()) right2=nums2[elementsRequiredFromNums2];
            else right2=INT_MAX;
            // check the boundaries
            if(left2>right1){
                // the last element of left part > the first element of right part
                s=mid+1;
            }
            else if(left1>right2){
                e=mid-1;
            }
            else {
                // correct wall 
                if(totalElements%2==0){
                    // even length
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                }
                else{
                    // odd length
                    return max(left1,left2);
                }
            }
        }
        return -1;
    }
};