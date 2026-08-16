class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            //3 cases
            // 1
            if(st.empty()) st.push({ch,1});
            // 2
            else if(st.top().first!=ch){
                st.push({ch,1});
            }
            // 3
            else if(st.top().first==ch){
                // isme bhi 2 cases
                if(st.top().second==k-1) st.pop();
                else{
                    auto topPair=st.top(); st.pop();
                    char first=topPair.first;
                    int second=topPair.second;
                    st.push({first,second+1});
                }
            }
        }
        // make the ans
        string ans="";
        while(!st.empty()){
            auto topPair=st.top(); st.pop();
            char first=topPair.first;
            int second=topPair.second;
            while(second--) ans+=first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};