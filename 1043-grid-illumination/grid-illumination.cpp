class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_set<long long>lampsOn;
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        unordered_map<int,int>mainDiagonal;
        unordered_map<int,int>antiDiagonal;
        for(int i=0;i<lamps.size();i++){
            int r=lamps[i][0];
            int c=lamps[i][1];
            long long key=1LL*n*r+c;
            if(!lampsOn.count(key)){
                row[r]++;
                col[c]++;
                mainDiagonal[r-c]++;
                antiDiagonal[r+c]++;
            }
            lampsOn.insert(key);
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int r=queries[i][0];
            int c=queries[i][1];
            if(row[r]>0 or col[c]>0 or mainDiagonal[r-c]>0 or antiDiagonal[r+c]>0) ans[i]=1;
            /// turn off this 
            // and its 8 nbr
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    int newX=r+x;
                    int newY=c+y;
                    if(newX>=0 and newY>=0 and newX<n and newY<n){
                        long long key=1LL*newX*n+newY;
                        if(lampsOn.count(key)){
                            // this lamp is on
                            row[newX]--;
                            col[newY]--;
                            mainDiagonal[newX-newY]--;
                            antiDiagonal[newX+newY]--;
                            lampsOn.erase(key);
                        }
                    }
                }
            }
        }
        return ans;
    }
};