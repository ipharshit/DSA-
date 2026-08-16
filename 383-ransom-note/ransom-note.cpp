class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        for(int i=0;i<magazine.size();i++) arr[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();i++){
            char ch=ransomNote[i];
            if(arr[ch-'a']==0) return false;
            arr[ch-'a']--;
        }
        return true;
    }
};