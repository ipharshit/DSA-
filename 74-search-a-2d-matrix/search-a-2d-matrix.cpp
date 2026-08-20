class Solution {
public:
// 1 pass method 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int s=0;
        int e=(rows*cols)-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            int rowIndex=mid/cols;
            int colIndex=mid%cols;
            if(target==matrix[rowIndex][colIndex]) return true;
            else if(target>matrix[rowIndex][colIndex]) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};