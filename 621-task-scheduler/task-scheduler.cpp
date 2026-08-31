class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int seat=1;
        unordered_map<char,int>freq;
         unordered_map<char,int>nextFreeSeat;
        for(auto ch:tasks){
             freq[ch]++;
             // initially to sab pehli seat par baith hi sakte hain
             nextFreeSeat[ch]=1;
        }
        priority_queue<pair<int,char>>pq;
        for(auto m:freq){
            pq.push({m.second,m.first});
        }
        while(!pq.empty()){
            vector<pair<char,int>>temp;
            while(!pq.empty()){
                auto top=pq.top(); pq.pop();
                int f=top.first;
                int ch=top.second;
                if(nextFreeSeat[ch]<=seat){
                    // isko bitha sakte h
                    // pehle hi baith jana chahiye tha 
                    if(f!=1) pq.push({f-1,ch});
                    nextFreeSeat[ch]+=n+1;
                    break;
                }
                else{
                    // isko nhi bitha skte
                    temp.push_back({ch,f});
                }
            }
            // yaha aaya kyyuki ya to koi baith gya 
            // ya koi nahi baitha
            for(auto t:temp){ 
                pq.push({t.second,t.first});
            }
            seat++;
        }
        return seat-1;
    }
};