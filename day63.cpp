// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order


#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;  // number of adjacent vertices

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    int s;
    cin >> s;

    vector<bool> visited(n, false);

    // DFS traversal
    DFS(s, adj, visited);

    return 0;
}