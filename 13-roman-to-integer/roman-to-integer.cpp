class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int>mp={
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}  };
        int ans=0;
        //traversing over the whole string
        for(int i=0;i<s.size();i++){
           char ch=s[i];
           // iska number map se nikaal
           int current = mp[ch];
           // compare with the next
           if(i+1<s.size() and current<mp[s[i+1]]){
            // subtraction vala case
            int next=mp[s[i+1]];
            ans+=next-current;
            //yeh imprtant hai
            i++;
           }
           else{
            //simple -> addition vala case
            ans+=current;
           }
        }
        return ans;
    }
};