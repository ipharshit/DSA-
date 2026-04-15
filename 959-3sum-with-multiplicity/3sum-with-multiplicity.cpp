class Solution {
public:
const int MOD = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target){
        // 3 sum hai to -> sort
        sort(arr.begin(),arr.end());
        long long c=0;
        for(int i=0;i<arr.size();i++){
            int a=i+1;
            int b=arr.size()-1;
            int t=target-arr[i];
            while(a<b){
                //isme 3 cases bnte h -> ==,>,<
                //pehla
                if(arr[a]+arr[b]==t){
                    // ab isme bhi 2 case bane
                    if(arr[a]!=arr[b]){
                        // dono ke duplicates count karo
                        //count left vale ke
                        int leftduplicates=0;
                        int leftvalue=arr[a];
                        while(a<b and leftvalue==arr[a]){
                            leftduplicates++;
                            a++;
                        }
                        //similarly right vale ke
                        int rightduplicates=0;
                        int rightvalue=arr[b];
                        while(b>=a and rightvalue==arr[b]){
                            rightduplicates++;
                            b--;
                        }
                        int totalduplicates = (leftduplicates*rightduplicates)%MOD;
                        c+=(totalduplicates)%MOD;
                    }
                
                    else if(arr[a]==arr[b]){
                        //in dono ke beech mein aur kuch nahi hai
                        // sirf yeh dono khud hain
                        //count duplicates -> count of both
                        // since both are same
                        int length = b-a+1;
                        int duplicates = (length*(length-1)/2)%MOD; //same as nCr = n!(n-r)!r! = since r=2=> n!/(n-2)!2! ==== n*(n-1)/2
                        c+=duplicates;
                        // ab aage kuch bacha hi nahi
                        break;
                    }
                }
                //dusra
                else if(arr[a]+arr[b]>t){
                    //move left
                    b--;
                }
                // teesra
                else{
                    //move  right
                    a++;
                }
        }
        }
        return c%MOD;
    }
};