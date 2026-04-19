class Solution {
public:
    bool backspaceCompare(string s, string t) { 
       int i=s.size()-1;
       int j=t.size()-1;
       int skips=0;
       int skipt=0;
       // traversing from right to left 
       while(i>=0 or j>=0){
        // process s first
        while(i>=0){
            if(s[i]=='#'){
                skips++;
            }
            else if(s[i]!='#' and skips>0){
                // skip it
                skips--;
            }
            else{
                // skips<0 -> go to t
                break;
            }
            // peeche to jana hi hai
            i--;
        }
        // now process t
        while(j>=0){
            if(t[j]=='#'){
                skipt++;
            }
            else if(t[j]!='#' and skipt>0){
                //skip it
                skipt--;
            }
            else{
                // skipt< 0 -> break
                break;
            }
            // peeche to jana hi h
            j--;
        }
        // yaha aa gaya matlab dono valid characters par hain
        // compare caro
        if(i>=0 and j>=0){
            if(s[i]==t[j]){
            // dono barabar -> aage check kro
            i--;
            j--;
            }
            else{ 
            // dono not equal
            return false;
            }
        }
        else{
            if(i>=0 or j>=0) return false;
        }
       }
       // yaha aa gaya matlab dono strings complete ho gayi
       return true;
    }
};