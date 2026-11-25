class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int globalMin=INT_MAX;
        for(int i=0;i<basket1.size();i++){
            mp[basket1[i]]++;
            globalMin = min(globalMin, basket1[i]);
        }
        for(int i=0;i<basket2.size();i++){
            mp[basket2[i]]--;
            globalMin = min(globalMin, basket2[i]);
        }
        vector<int>extraFruits;
        for(auto m:mp){
            if(m.second==0) continue;
            int f=m.second;
            int reqSwaps=abs(f)/2;
            if(abs(f)%2!=0) return -1;
            while(reqSwaps--) extraFruits.push_back(m.first);
        }
        if(extraFruits.empty()) return 0;
        sort(extraFruits.begin(),extraFruits.end());
        long long int cost=0;
        for(int i=0;i<extraFruits.size()/2;i++){
            cost+=min(globalMin*2,extraFruits[i]);
        }
        return cost;
    }
};