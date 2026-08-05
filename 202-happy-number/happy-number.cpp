class Solution {
public:
int sumSquare(int n){
    int sum=0;
    while(n!=0){
        int digit=n%10;
        sum+=digit*digit;
        n/=10;
    }
    return sum;
}
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        bool isOne=0;
        while(fast!=1){
            slow=sumSquare(slow);
            fast=sumSquare(sumSquare(fast));
            if(fast==slow){
                if(fast==1) isOne=1;
                return isOne;
            } 
        }
        return true;
    }
};