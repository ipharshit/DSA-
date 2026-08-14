class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(st.empty()) st.push(ch);
            else if(st.top()==ch){
                st.pop();
                continue;
            }
            else st.push(ch);
        }
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};