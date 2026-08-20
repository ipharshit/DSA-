class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=0;
        // last vali row ke first column se start karte hain
        while(row>=0 and col<matrix[0].size()){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target){
                // aage row mein bhi isse bade hi honge
                // col mein chote mil sakte h
                // move up
                row--;
            }
            else{
                // upar col mein bhi isse chote hi honge
                // aage row mein isse bade mil sakte hain
                col++;
            }
        }
        return false;
    }
};