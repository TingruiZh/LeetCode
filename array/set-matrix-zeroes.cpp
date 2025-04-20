class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> newmatrix;
        newmatrix = matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                for (int col = 0; col < matrix[0].size(); col++) {
    newmatrix[i][col] = 0;
}
for (int row = 0; row < matrix.size(); row++) {
    newmatrix[row][j] = 0;
}



                }
            }
        }
        matrix = newmatrix;
    }
};