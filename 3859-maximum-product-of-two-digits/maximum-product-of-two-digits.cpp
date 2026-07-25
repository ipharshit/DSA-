class Solution {
public:
    int maxProduct(int n) {
        // vector<int>digits;
        int first=INT_MIN,second=INT_MIN;
        while(n!=0){
            int digit=n%10;
            if(digit>first) {
                second=first;
                first=digit;
            }
            else if(digit>second) second=digit;

            n/=10;
        }
        return first*second;
    }
};