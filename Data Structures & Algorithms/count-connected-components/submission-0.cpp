class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
        if (visited[node]) return;
        visited[node] = true;

        for (int& neighbor: graph[node]) {
            if (!visited[neighbor]) 
                dfs(neighbor, visited, graph);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int comps = 0;

        vector<vector<int>> graph(n);
        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        vector<bool> visited(n, false);
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                dfs(i, visited, graph);
                comps++;
            }
        }

        return comps;
    }
};
