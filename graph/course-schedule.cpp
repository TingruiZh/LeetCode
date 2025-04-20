class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // 邻接表
        vector<int> indegree(numCourses, 0);   // 入度表

        // 构图 & 统计入度
        for (auto& p : prerequisites) {
            int to = p[0], from = p[1];
            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i); // 入度为 0 的课程可以先学
        }

        int count = 0; // 完成课程数
        while (!q.empty()) {
            int course = q.front(); q.pop();
            count++;

            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses; // 所有课程都能完成才返回 true
    }
};
