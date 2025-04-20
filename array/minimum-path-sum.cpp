class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
         if (n == 0) return 0;
        int m = grid[0].size();
       vector<vector<int>> sums(n, vector<int>(m, 0));
        
        sums[0][0]=grid[0][0];
                // 第一行
        for (int j = 1; j < m; ++j) {
            sums[0][j] = grid[0][j] + sums[0][j - 1];
        }
        // 第一列
        for (int i = 1; i < n; ++i) {
            sums[i][0] = grid[i][0] + sums[i - 1][0];
        }
        for(int i =1;i<n;i++){
            for(int j = 1; j<m;j++){
             sums[i][j]=grid[i][j]+min(sums[i-1][j],sums[i][j-1]);
            }
        }
        return sums[n-1][m-1];
    }
};