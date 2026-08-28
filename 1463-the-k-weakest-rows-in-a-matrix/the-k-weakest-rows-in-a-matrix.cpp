class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // count the no. of soldiers in each row
        unordered_map<int,int>mp;
        for(int i=0;i<mat.size();i++){
            int countSoldiers=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    // civilian -> iske aage koi soldier nahi milega
                    break;
                }
                countSoldiers++;
            }
            mp[i]=countSoldiers;
        }
        // find top k rows with less no. of soldiers
        priority_queue<pair<int,int>>pq;
        for(auto num:mp){
            // num-> pair
            int currSoldier=num.second;
            int rowIndex=num.first;
            if(pq.size()<k) pq.push({currSoldier,rowIndex});
            else if(currSoldier<pq.top().first){
                pq.pop();
                pq.push({currSoldier,rowIndex});
            }
            else if(pq.top().first==currSoldier and rowIndex< pq.top().second){
                pq.pop();
                pq.push({currSoldier,rowIndex});
            }
        }
        // yaha mere paas k weakest rows hongi
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};