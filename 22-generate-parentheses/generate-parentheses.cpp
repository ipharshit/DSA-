class Solution {
public:
void solve(int n,int open,int close,string &s,vector<string>&ans){
    if(open==n and close==n){
        // yaha par mere paas 1 valid ans h
        ans.push_back(s);
        return;
    }
    if(open>n or close>n) return;
    // open brackets to kahi bhi add kar sakte h
    s+='(';
    solve(n,open+1,close,s,ans);
    // backtrace
    s.pop_back();

    // close bracket tab add karenege jab uske liye koi open hoga
    if(close<open){
        s+=')';
        solve(n,open,close+1,s,ans);
        // backtrace
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string s="";
        vector<string>ans;
        solve(n,open,close,s,ans);
        return ans;
    }
};