// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0);

        // Check all components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution sol;

    if (sol.hasCycle(n, adj))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}