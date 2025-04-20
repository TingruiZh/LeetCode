class Solution {
public:
    int n, m, originalColor;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        originalColor = image[sr][sc];

        if (originalColor == color) return image; // 避免死循环

        dfs(image, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int color) {
        if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != originalColor)
            return;

        image[x][y] = color;

        dfs(image, x + 1, y, color);
        dfs(image, x - 1, y, color);
        dfs(image, x, y + 1, color);
        dfs(image, x, y - 1, color);
    }
};
