## Title 
BFS and DFS Using Adjacency List

## Objective

To accept a graph from the user, represent it using an adjacency list,
and perform BFS and DFS traversals.

## Theory

Graphs can be represented efficiently using an adjacency list, where
each vertex stores a list of its connected vertices.

### Breadth First Search (BFS)

-   Uses a queue.
-   Traverses level by level.
-   Useful for shortest path in unweighted graphs.

### Depth First Search (DFS)

-   Uses recursion or a stack.
-   Traverses deep into a branch before backtracking.
-   Useful for cycle detection, topological sorting, and connectivity.

## Code

``` cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int nodes_rdk;
    vector<int> adj_rdk[50];   // adjacency list

public:
    Graph() {
        nodes_rdk = 0;
    }

    void acceptGraph() {
        int edges_rdk;
        cout << "Enter number of nodes: ";
        cin >> nodes_rdk;

        cout << "Enter number of edges: ";
        cin >> edges_rdk;

        // clear previous data
        for (int i = 0; i < nodes_rdk; i++)
            adj_rdk[i].clear();

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < edges_rdk; i++) {
            int u_rdk, v_rdk;
            cin >> u_rdk >> v_rdk;

            adj_rdk[u_rdk].push_back(v_rdk);
            adj_rdk[v_rdk].push_back(u_rdk); // undirected graph
        }

        cout << "Graph stored successfully!\n";
    }

    void displayGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < nodes_rdk; i++) {
            cout << i << " -> ";
            for (int x : adj_rdk[i])
                cout << x << " ";
            cout << endl;
        }
    }

    void BFS(int start_rdk) {
        vector<bool> visited_rdk(nodes_rdk, false);
        queue<int> q_rdk;

        q_rdk.push(start_rdk);
        visited_rdk[start_rdk] = true;

        cout << "BFS Traversal: ";

        while (!q_rdk.empty()) {
            int node_rdk = q_rdk.front();
            q_rdk.pop();
            cout << node_rdk << " ";

            for (int neigh_rdk : adj_rdk[node_rdk]) {
                if (!visited_rdk[neigh_rdk]) {
                    visited_rdk[neigh_rdk] = true;
                    q_rdk.push(neigh_rdk);
                }
            }
        }
        cout << endl;
    }

    void dfsUtil(int node_rdk, vector<bool> &visited_rdk) {
        visited_rdk[node_rdk] = true;
        cout << node_rdk << " ";

        for (int neigh_rdk : adj_rdk[node_rdk]) {
            if (!visited_rdk[neigh_rdk])
                dfsUtil(neigh_rdk, visited_rdk);
        }
    }

    void DFS(int start_rdk) {
        vector<bool> visited_rdk(nodes_rdk, false);
        cout << "DFS Traversal: ";
        dfsUtil(start_rdk, visited_rdk);
        cout << endl;
    }
};


int main() {
    Graph g_rdk;
    int choice_rdk, start_rdk;

    while (true) {
        cout << "\n===== BFS & DFS MENU =====\n";
        cout << "1. Accept Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                g_rdk.acceptGraph();
                break;

            case 2:
                g_rdk.displayGraph();
                break;

            case 3:
                cout << "Enter starting node: ";
                cin >> start_rdk;
                g_rdk.BFS(start_rdk);
                break;

            case 4:
                cout << "Enter starting node: ";
                cin >> start_rdk;
                g_rdk.DFS(start_rdk);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

```

## Sample Output

    Enter number of vertices: 5
    Enter number of edges: 4
    0 1
    0 2
    1 3
    2 4
    Enter starting vertex: 0

    BFS: 0 1 2 3 4
    DFS: 0 1 3 2 4

## Dry Run (Simplified)

### BFS

Start = 0\
Queue = \[0\] → visit 0\
Add neighbors: 1, 2\
Queue = \[1,2\]\
Visit 1 → add 3\
Visit 2 → add 4\
Result: **0 1 2 3 4**

### DFS

Start = 0\
Go to 1 → then 3\
Backtrack to 0 → go to 2 → then 4\
Result: **0 1 3 2 4**

## Conclusion

Using adjacency lists is memory-efficient for sparse graphs. BFS
explores the graph level-wise, while DFS explores depth-wise. Both
methods are essential for graph analysis, connectivity checking, and
solving traversal-based problems.