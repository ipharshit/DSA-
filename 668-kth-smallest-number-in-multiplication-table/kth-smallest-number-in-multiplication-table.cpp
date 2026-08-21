class Solution {
public:
int foundElementsLessthanMyGuess(int m,int n,int guess){
    int count=0;
    int row=m;
    int col=1;
    int totalRows=m;
    int totalCols=n;
    while(col<=n and row>=1){
        if(row*col>guess) row--;
        else{
            col++;
            count+=row;
        }
    }
    return count;
}
    int findKthNumber(int m, int n, int k) {
        // isse pehle search a 2d matrix II dekh lena 
        // defining the search space]
        // 1st element -> 1*1=1 [1-based indexing]
        // last element -> m*n
        // size of matrix -> m*n
        int ans=-1;
        int s=1;
        int e=m*n;
        while(s<=e){
            int mid=s+((e-s)>>1);
            int c=foundElementsLessthanMyGuess(m,n,mid);
            if(c<k){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};