// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    // Number of vertices
    cin >> n;

    // Number of edges
    cin >> m;

    // Adjacency list
    vector<vector<int>> adj(n);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // For an undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print adjacency lists
    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int v : adj[i]) {
            cout << v << " ";
        }

        cout << endl;
    }

    return 0;
}