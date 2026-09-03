// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S) {
    // dist[i] = shortest distance from source S to vertex i
    vector<int> dist(V, INT_MAX);

    // Min-heap: {distance, vertex}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entry
        if (d > dist[u])
            continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            // Relaxation
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Remove this for directed graph
    }

    int S;
    cin >> S;

    vector<int> dist = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << "Distance from " << S << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}