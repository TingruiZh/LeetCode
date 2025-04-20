class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O' || visited[x][y])
            return;

        visited[x][y] = true;

        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        // 1. 从边缘出发标记所有不会被包围的 'O'
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
        }

        // 2. 遍历整个棋盘，把未标记的 'O' 改为 'X'（被包围），已标记的保持
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
