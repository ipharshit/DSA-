class Solution {
public:
int sum(int n){
    int temp=n;
    int sum=0;
    while(temp!=0){
        int digit=temp%10;
        sum+=digit;
        temp/=10;
    }
    return sum;
}
int product(int n){
    int temp=n;
    int product=1;
    while(temp!=0){
        int digit=temp%10;
        product*=digit;
        temp/=10;
    }
    return product;
}
    bool checkDivisibility(int n) {
        int sumOfDigits=sum(n);
        int productOfDigits=product(n);
        int totalSum=sumOfDigits+productOfDigits;
        return n%totalSum==0;
    }
};