class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        unordered_set<string>st;
        // 1 st wind
        string str;
        for(int i=0;i<k;i++){
            str+=s[i];
        }
        st.insert(str);
        // remaining windows
        for(int i=k;i<s.size();i++){
            str.erase(0,1);
            str+=s[i];
            st.insert(str);
        }
        long long totalCodes=pow(2,k);
        if(st.size()==totalCodes) return true;
        else return false;
    }
};