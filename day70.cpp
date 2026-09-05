// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    const int INF = 1e9;
    vector<int> dist(n, INF);

    dist[source] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;

        for (auto edge : edges) {
            if (dist[edge.u] != INF &&
                dist[edge.u] + edge.w < dist[edge.v]) {

                dist[edge.v] = dist[edge.u] + edge.w;
                updated = true;
            }
        }

        // Optimization: stop if no distance was updated
        if (!updated)
            break;
    }

    // Check for negative weight cycle
    for (auto edge : edges) {
        if (dist[edge.u] != INF &&
            dist[edge.u] + edge.w < dist[edge.v]) {

            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        if (i != n - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}