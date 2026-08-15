class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int currTemp=temperatures[i];
            // to calc. index diff-> i have to store the index
            while(!st.empty() and temperatures[st.top()]<=currTemp) st.pop();
            // yaha aa gya ke 2 chances hain
            // ya to stack empty
            if(st.empty()) ans[i]=0;
            // ya fir isse bada temperatufre mil gya
            else ans[i]=st.top()-i;
            // current element to push karna hi h
            st.push(i);
        }
        return ans;
    }
};