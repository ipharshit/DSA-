class Solution {
public:
    bool isPalindrome(int x) {
        int original=x;
        long reversed=0;
        if(x<0) return false;
        while(x!=0){
            int rem=x%10;
            reversed=reversed*10+rem;
            x=x/10;
        }
        if(reversed==original) return true;
        else return false;
        
    }
};