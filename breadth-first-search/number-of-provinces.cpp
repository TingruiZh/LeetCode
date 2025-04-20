class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < graph.size(); ++j) {
            if (graph[i][j] == 1 && !visited[j]) {
                dfs(graph, visited, j);
            }
        }
    }
};
