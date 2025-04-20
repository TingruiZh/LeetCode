class Solution {
public:
    // 记忆化数组，-1 表示尚未计算
    vector<vector<int>> memo;

    int uniquePaths(int m, int n) {
        // 在最外层调用时初始化 memo 大小
        if (memo.empty()) {
            memo.assign(m + 1, vector<int>(n + 1, -1));
        }
        return dfs(m, n);
    }

private:
    int dfs(int i, int j) {
        // 越界：不能走到
        if (i <= 0 || j <= 0) 
            return 0;
        // 终点：只有一条路径到 (1,1)
        if (i == 1 && j == 1) 
            return 1;
        // 如果已经计算过，直接返回
        if (memo[i][j] != -1) 
            return memo[i][j];
        // 递归状态转移——严格按 “你的思路”
        return memo[i][j] = dfs(i - 1, j) + dfs(i, j - 1);
    }
};
