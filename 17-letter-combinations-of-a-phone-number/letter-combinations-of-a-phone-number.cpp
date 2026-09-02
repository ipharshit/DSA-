class Solution {
public:
void solve(string &digits,unordered_map<char,string>&mp,string &s,vector<string>&ans,int i){
    // BC
    if(i==digits.size()){
        // yaha par meri string khatam ho chuki h
        ans.push_back(s);
        return;
    }
    // to pick each 1 by 1 character from 3
    for(char ch:mp[digits[i]]){
        s.push_back(ch);
        solve(digits,mp,s,ans,i+1);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        // store the alphabets of a number
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        int i=0;
        string s="";
        vector<string>ans;
        solve(digits,mp,s,ans,i);
        return ans;
    }
};