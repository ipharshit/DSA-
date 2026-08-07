class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int ans=nodelete;
        int onedelete=-1e9;
        for(int i=1;i<arr.size();i++){
            int oldonedelete=onedelete;
            int oldnodelete=nodelete;
            onedelete=max(oldnodelete,oldonedelete+arr[i]);
            nodelete=max(arr[i],oldnodelete+arr[i]);
            ans=max(ans,max(nodelete,onedelete));
        }
        return ans;
    }
};