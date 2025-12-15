## Title
Dijkstra's Algorithm Using Adjacency List

## Objective

To implement Dijkstra's Algorithm to find the shortest distance between
two nodes in a user-defined weighted graph using an adjacency list.

## Theory

Dijkstra's Algorithm is a greedy algorithm used to compute the shortest
path from a source node to all other nodes in a weighted graph with
non-negative edge weights.

Steps: 1. Initialize all distances as infinity except the source node,
which is set to 0. 2. Use a priority queue to always pick the node with
the smallest distance. 3. Update the distances of neighboring nodes. 4.
Repeat until all reachable nodes are processed.

Dijkstra works efficiently using an adjacency list and min-priority
queue.

## Code

``` cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int,int>> adj[100];

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> end;

    vector<int> dist(n, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int node = p.second;

        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int next = it.first;
            int weight = it.second;
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest Distance: " << dist[end];
    return 0;
}
```

## Sample Output

    Enter number of vertices: 5
    Enter number of edges: 6
    0 1 2
    0 2 4
    1 2 1
    1 3 7
    2 4 3
    3 4 1
    Enter start node: 0
    Enter destination node: 4
    Shortest Distance: 6

## Dry Run (Simplified)

Graph: - (0--1,2) - (0--2,4) - (1--2,1) - (1--3,7) - (2--4,3) - (3--4,1)

Start at 0: - dist = \[0,2,4,∞,∞\] - From 1 → update 2 = 3, 3 = 9 - From
2 → update 4 = 6 - From 4 → destination reached

Shortest distance from 0 to 4 = **6**

## Conclusion

Dijkstra's Algorithm efficiently computes the shortest shortest path in
a weighted graph using a priority queue. It guarantees the minimum
distance when all edge weights are non-negative and is widely used in
routing, GPS navigation, and network optimization