// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, 
         vector<int>& visited, vector<int>& recStack) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for (int neighbor : adj[node]) {
        // If neighbor is in current recursion stack -> cycle
        if (recStack[neighbor])
            return true;

        // If not visited, perform DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
    }

    recStack[node] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // directed edge u -> v
    }

    vector<int> visited(n, 0);
    vector<int> recStack(n, 0);

    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                cycle = true;
                break;
            }
        }
    }

    cout << (cycle ? "YES" : "NO") << endl;

    return 0;
}