class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        unordered_map<char,int>mp;
        // store the freq of each char
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        priority_queue<pair<int,char>>pq;
        // push into heap
        for(auto m:mp) pq.push({m.second,m.first});
        // now, to reorganize-> i will try to finish the higher freq first-> jisse last vale same bacche dikkat na kare
        while(!pq.empty()){
            auto pair1=pq.top();  pq.pop();
            int freq=pair1.first;
            char ch=pair1.second;
            if(ans.empty() or ch!=ans.back()){
                ans+=ch;
                if(freq!=1) pq.push({freq-1,ch});
            }
            else{
                // last element same h
                // seat kahli to chhod nahi sakte
                // kisi aur ko daal do
                if(pq.empty()) return "";
                auto pair2=pq.top(); pq.pop();
                int f=pair2.first;
                char c=pair2.second;
                ans+=c;
                if(f!=1) pq.push({f-1,c});
                pq.push({freq,ch});
            }
        }
        return ans;
    }
};