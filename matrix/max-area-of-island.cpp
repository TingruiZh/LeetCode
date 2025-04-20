class Solution {
public:
int count,maxArea = 0;
 int n,m;
 vector<vector<bool>>visited ;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
         n = grid.size();
         m = grid[0].size();
         visited = vector<vector<bool>>(n, vector<bool>(m, false));
 for(int i = 0; i<n; i++){
    for(int j=0;j<m;j++){
        if((grid[i][j]==1)&&!visited[i][j]){
           int area = dfs(grid, i, j);
        maxArea = max(maxArea, area);
        }
    }
 }
 return maxArea;
    }
    int dfs(vector<vector<int>>&grid, int x, int y){
         if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1||visited[x][y])
            return 0;
        visited[x][y]=true;
        count=1+
        dfs(grid, x + 1, y)+
        dfs(grid, x - 1, y)+
        dfs(grid, x, y + 1)+
        dfs(grid, x, y - 1);
        return count;
    }
};