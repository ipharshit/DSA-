class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int s=0;
        int e=rows-1;
        // let's find the row which contains tthe target
        int targetRow=-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target){
                // isme aur isse agle valo mein target nahi mil sakta
                e=mid-1;
            }
            else{
                // isme or isse agle valo main target mil skt ahai
                targetRow=mid;
                s=mid+1;
            }
        }
        // now search the target in that row
        if(targetRow==-1) return false;
        s=0;
        e=cols-1;
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(matrix[targetRow][mid]==target) return true;
            else if(target>matrix[targetRow][mid]) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};