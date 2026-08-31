class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        // sort the vector by capital so that i have min capital first
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        // k projects
        int i=0;
        while(k--){
            // finding the maximum profit in 1 time(1 iteration)
            while(i<v.size()){
                int currCapital=v[i].first;
                int currProfit=v[i].second;
                if(currCapital>w){
                    // iske aage bhi select nhi kr pauga because array is sorted by capital
                    break;
                }
                // isko select kr skta hu
                // but i want max profit among it aur jise bhi select kr pau is itrn mein
                pq.push(currProfit);
                i++; 
            }
            // yaha par mere pass sare profit honge
            // find the max one
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};