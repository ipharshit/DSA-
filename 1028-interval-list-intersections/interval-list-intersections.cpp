class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size()==0) return firstList;
        if(secondList.size()==0) return secondList;
         vector<vector<int>> ans;
        int i=0,j=0;
        while(i<firstList.size() and j<secondList.size()){
            int start1=firstList[i][0];
            int end1=firstList[i][1];
            int start2=secondList[j][0];
            int end2=secondList[j][1];
            if(max(start1,start2) <= min(end1,end2)) ans.push_back({max(start1,start2),min(end1,end2)});
            if(end1>end2) j++;
            else i++;
        }
        return ans;
    }
};