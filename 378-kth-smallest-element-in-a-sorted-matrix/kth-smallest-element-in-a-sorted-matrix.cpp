class Solution {
public:
int findElementsLessThanMyGuess(vector<vector<int>>& matrix,int guess){
    int row=matrix.size()-1;
    int col=0;
    int count=0;
    while(col<matrix[0].size() and row>=0){
        if(matrix[row][col]>guess){
            // puri row mein sab us se bade hi hoge
            // aur mujhe chahiye chote
            row--;
        }
        else{
            // pure col mein usse chote hi honge'
            // i have to include all of them
            count+=row+1;
            col++; 
        }
    }
    return count;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // defining the search space
        int s=matrix[0][0];
        int e=matrix[matrix.size()-1][matrix[0].size()-1];
        int ans=-1;
        // apply binaey search on it
        while(s<=e){
            int mid=s+((e-s)>>1);
            int c= findElementsLessThanMyGuess(matrix,mid);
            if(c<k){
                // yeh to mera anser kabjhi nahi bn sakta 
                // aur isse chote bhi 
                // because i want kth min-> but it is less than k
                s=mid+1;
            }
            else if(c>=k){
                // yeh mera answer ho sakta h
                ans=mid;
                // but to check if this exists in m,atrix
                e=mid-1;
            }
        }
        return ans;
    }
};