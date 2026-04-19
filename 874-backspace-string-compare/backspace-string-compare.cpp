class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        string s2="";
        stack<char>st1,st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){ 
                if(!st1.empty()) st1.pop();
            }
            else st1.push(s[i]);
        }
         for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!st2.empty()) st2.pop();
            }
            else st2.push(t[i]);
        }
        while(!st1.empty()){
            s1+=st1.top();
            st1.pop();
        }
        while(!st2.empty()){
            s2+=st2.top();
            st2.pop();
        }
        return s1==s2; 
    }
};