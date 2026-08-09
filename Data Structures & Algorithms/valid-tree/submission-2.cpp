class Solution {
public:
    int findParent(vector<int>& parent, int u) {
        if (parent[u] == u) return u;
        return findParent(parent, parent[u]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for (int i=0;i<n;i++) parent[i] = i;

        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int x = findParent(parent, u);
            int y = findParent(parent, v);
            
            if (x==y) return false;

            if (rank[x] <= rank[y]) {
                parent[y] = x;
                rank[x]++;
            }
            else {
                parent[x] = y;
                rank[y]++;
            }
        }
        return true;
    }
};
