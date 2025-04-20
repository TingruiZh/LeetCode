class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // 1. 初始化：把所有腐烂橘子加入队列，并统计新鲜橘子数
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0; // 没有新鲜橘子

        int minutes = 0;
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 4个方向

        while (!q.empty()) {
            int size = q.size();
            bool changed = false;

            // 当前这一分钟扩散
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        changed = true;
                    }
                }
            }

            if (changed) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
