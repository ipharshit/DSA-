class Solution {
public:
int productOfDigits(int n){
    int product=1;
    while(n!=0){
        int digit=n%10;
        product*=digit;
        n/=10;
    }
    return product;
}
    int smallestNumber(int n, int t) {
        int curr=n;
        while(true){
            int product=productOfDigits(curr);
            if(product%t==0) return curr;
            curr++;
        }
        return 0;
    }
};