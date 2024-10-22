class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            if(matrix[i][cols-1]>=target){
                //checking last element of each rw
                //ans is in that row
                //search in that row
                //traverse columns
                for(int j=0;j<cols;j++){
                    if(matrix[i][j]==target){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};