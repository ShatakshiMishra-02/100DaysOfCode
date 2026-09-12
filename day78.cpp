// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);

    // {weight, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, 1});

    int totalWeight = 0;
    int count = 0;

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;

        if (visited[node])
            continue;

        visited[node] = true;
        totalWeight += weight;
        count++;

        for (pair<int, int> edge : adj[node]) {
            int next = edge.first;
            int edgeWeight = edge.second;

            if (!visited[next]) {
                pq.push({edgeWeight, next});
            }
        }
    }

    if (count != n)
        cout << "MST does not exist";
    else
        cout << totalWeight;

    return 0;
}