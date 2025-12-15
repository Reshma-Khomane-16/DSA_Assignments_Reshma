## Title 
Kruskal's Algorithm Using Adjacency List

## Objective

To implement Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
of a user-defined graph using an adjacency list and edge list
representation.

## Theory

Kruskal's Algorithm is a greedy method used to find the Minimum Spanning
Tree (MST) of a connected, undirected, and weighted graph.

Steps: 1. Sort all edges in increasing order of weight. 2. Pick the
smallest edge. If it does not form a cycle with the previously selected
edges, include it in the MST. 3. Use Disjoint Set Union (DSU) or
Union-Find to detect cycles efficiently. 4. Repeat until MST has (V
-- 1) edges.

## Code

``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int nodes_rdk;  
    vector<pair<int, pair<int, int>>> edges_rdk; // (weight, (u, v))

public:
    Graph() {
        nodes_rdk = 0;
    }

    void acceptGraph() {
        int edgesCount_rdk;
        edges_rdk.clear();

        cout << "Enter number of nodes: ";
        cin >> nodes_rdk;

        cout << "Enter number of edges: ";
        cin >> edgesCount_rdk;

        cout << "Enter edges in format: u v weight\n";
        for (int i = 0; i < edgesCount_rdk; i++) {
            int u_rdk, v_rdk, w_rdk;
            cin >> u_rdk >> v_rdk >> w_rdk;

            edges_rdk.push_back({w_rdk, {u_rdk, v_rdk}});
        }

        cout << "Graph stored successfully.\n";
    }

    // DSU (Disjoint Set Union)
    int findParent(int v, vector<int> &parent_rdk) {
        if (parent_rdk[v] == v)
            return v;
        return parent_rdk[v] = findParent(parent_rdk[v], parent_rdk);
    }

    void unionSets(int a, int b, vector<int> &parent_rdk, vector<int> &rank_rdk) {
        a = findParent(a, parent_rdk);
        b = findParent(b, parent_rdk);

        if (a != b) {
            if (rank_rdk[a] < rank_rdk[b])
                swap(a, b);

            parent_rdk[b] = a;

            if (rank_rdk[a] == rank_rdk[b])
                rank_rdk[a]++;
        }
    }

    void kruskalMST() {
        if (nodes_rdk == 0) {
            cout << "Graph empty!\n";
            return;
        }

        sort(edges_rdk.begin(), edges_rdk.end()); // sort by weight

        vector<int> parent_rdk(nodes_rdk);
        vector<int> rank_rdk(nodes_rdk, 0);

        for (int i = 0; i < nodes_rdk; i++)
            parent_rdk[i] = i;

        int mstCost_rdk = 0;

        cout << "\nEdges in MST:\n";

        for (auto edge : edges_rdk) {
            int w_rdk = edge.first;
            int u_rdk = edge.second.first;
            int v_rdk = edge.second.second;

            int pu_rdk = findParent(u_rdk, parent_rdk);
            int pv_rdk = findParent(v_rdk, parent_rdk);

            if (pu_rdk != pv_rdk) {  
                cout << u_rdk << " --(" << w_rdk << ")--> " << v_rdk << endl;
                mstCost_rdk += w_rdk;
                unionSets(pu_rdk, pv_rdk, parent_rdk, rank_rdk);
            }
        }

        cout << "\nTotal Minimum Cost = " << mstCost_rdk << endl;
    }
};


int main() {
    Graph g_rdk;
    int choice_rdk;

    while (true) {
        cout << "\n===== KRUSKAL MST MENU =====\n";
        cout << "1. Accept Graph (Adjacency List Input)\n";
        cout << "2. Find MST using Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                g_rdk.acceptGraph();
                break;

            case 2:
                g_rdk.kruskalMST();
                break;

            case 3:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

```

## Sample Output

    Enter number of vertices: 4
    Enter number of edges: 5
    0 1 10
    0 2 6
    0 3 5
    1 3 15
    2 3 4

    MST Edges:
    2 - 3 : 4
    0 - 3 : 5
    0 - 1 : 10

    Total Weight of MST: 19

## Dry Run (Simplified)

Edges sorted by weight: - (2-3, 4) - (0-3, 5) - (0-2, 6) - (0-1, 10) -
(1-3, 15)

Step-by-step: - Pick (2-3, 4) - Pick (0-3, 5) - Skip (0-2, 6) --- forms
cycle - Pick (0-1, 10) MST complete → total weight = 19

## Conclusion

Kruskal's Algorithm is optimal for sparse graphs because it focuses on
sorting edges and using Union-Find for cycle detection. It produces an
MST with minimum total weight by always choosing the smallest available
edge that does not create a cycle.
