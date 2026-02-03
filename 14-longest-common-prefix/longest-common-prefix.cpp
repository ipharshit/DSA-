class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        if(strs[0].length()==1 and strs.size()==1) ans+=strs[0];
        for(int i=0;i<strs[0].size();i++){
            //travelling on first word characters
            char currentcharacter=strs[0][i];
            bool match=false;
            for(int j=1;j<strs.size();j++){
                //travelling on other words
                if(strs[j][i]=='\0') return ans;;
                if(strs[j]=="") return "";
                if( currentcharacter==strs[j][i]){
                    match=true;
                }
                else{ match=false;
                break;
                }
            }
            if(match) ans+=currentcharacter;
            else break;
        }
        return ans;
    }
};