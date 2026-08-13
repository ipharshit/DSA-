class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int new1=newInterval[0];
        int new2=newInterval[1];
        bool inserted=0;
        for(int i=0;i<intervals.size();i++){
            // i want to find the suitable place to place this
            int start2=intervals[i][0];
            int end2=intervals[i][1];
            if(!inserted and start2>=new1){
                // found a place
                ans.push_back({new1,new2});
                ans.push_back({start2,end2});
                inserted=1;
            }
            else{
                // current elem,ent to push karna hi h
                ans.push_back({start2,end2});
            }
        }
        // check if newinterval is inserted or not 
        if (!inserted) ans.push_back({new1, new2});
        // merging logic
        vector<vector<int>>v;
        int start1=ans[0][0];
        int end1=ans[0][1]; 
        // sort(ans.begin(),ans.end());
         for(int i=1;i<ans.size();i++){
            // i want to find the suitable place to place this
            int start2=ans[i][0];
            int end2=ans[i][1];
            if(end1>=start2){
                // merging 
                end1=max(end1,end2);
                continue;
            }
            v.push_back({start1,end1});
            start1=start2;
            end1=max(end1,end2);
         }
         v.push_back({start1,end1});
         return v;
    }
};