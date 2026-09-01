// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    // Add node after all its neighbours are processed
    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n, false);
    stack<int> st;

    // DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Print topological ordering
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}