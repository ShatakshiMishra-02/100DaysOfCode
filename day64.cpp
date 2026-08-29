// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int n, vector<vector<int>>& adj, int s) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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
        adj[v].push_back(u);  // Remove this for a directed graph
    }

    int s;
    cin >> s;

    cout << "BFS Traversal: ";
    BFS(n, adj, s);

    return 0;
}