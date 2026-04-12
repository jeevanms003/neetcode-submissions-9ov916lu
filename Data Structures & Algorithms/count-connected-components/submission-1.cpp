class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        // build adjacency list
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                components++;   // found one component
            }
        }

        return components;
    }
};
