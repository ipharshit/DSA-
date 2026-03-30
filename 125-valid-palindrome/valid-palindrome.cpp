class Solution {
public:
bool check(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}
string normalize(string s){
    string str;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' and s[i]<='z') str+=s[i];
        else if(s[i]>='A' and s[i]<='Z') str+=s[i]-'A'+'a';
        else if(s[i]>='0' and s[i]<='9') str+=s[i];
    }
    cout<<str;
    return str;
}
    bool isPalindrome(string s) {
        string str=normalize(s);
        return check(str);
    }
};