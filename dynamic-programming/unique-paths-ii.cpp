class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        // moves[i][j] = 到达 (i,j) 的路径数
        vector<vector<int>> moves(n, vector<int>(m, 0));

        // 起点
        if (obstacleGrid[0][0] == 0) 
            moves[0][0] = 1;

        // 第一行
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[0][j] == 0)
                moves[0][j] = moves[0][j - 1];
            else
                moves[0][j] = 0;
        }
        // 第一列
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] == 0)
                moves[i][0] = moves[i - 1][0];
            else
                moves[i][0] = 0;
        }

        // 普通格子：上 + 左
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    moves[i][j] = moves[i - 1][j] + moves[i][j - 1];
                } else {
                    moves[i][j] = 0;
                }
            }
        }

        return moves[n - 1][m - 1];
    }
};
