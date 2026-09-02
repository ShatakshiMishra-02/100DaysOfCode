// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Add vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    // Kahn's Algorithm
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Check for cycle
    if (topo.size() != n) {
        cout << "Cycle exists. Topological sorting not possible." << endl;
    } else {
        cout << "Topological Order: ";
        for (int v : topo)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}