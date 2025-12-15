## Title
Graph Traversal using Adjacency Matrix

## Objective

To accept a graph from the user, represent it using an adjacency matrix,
and perform BFS and DFS traversals.

## Theory

A graph can be represented using an adjacency matrix where each cell
indicates whether an edge exists between two vertices.\
Breadth First Search (BFS) explores nodes level by level using a queue.\
Depth First Search (DFS) explores nodes deeply using recursion or a
stack.

## Code

``` cpp
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int nodes_rdk;                 // number of nodes
    int adj_rdk[20][20];           // adjacency matrix

public:
    Graph() {
        nodes_rdk = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                adj_rdk[i][j] = 0;
    }

    void acceptGraph() {
        cout << "Enter number of nodes: ";
        cin >> nodes_rdk;

        cout << "Enter adjacency matrix (" << nodes_rdk << " x " 
             << nodes_rdk << "):\n";
        for (int i = 0; i < nodes_rdk; i++) {
            for (int j = 0; j < nodes_rdk; j++) {
                cin >> adj_rdk[i][j];
            }
        }

        cout << "Graph stored successfully.\n";
    }

    void displayMatrix() {
        if (nodes_rdk == 0) {
            cout << "Graph is empty!\n";
            return;
        }

        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < nodes_rdk; i++) {
            for (int j = 0; j < nodes_rdk; j++) {
                cout << adj_rdk[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start_rdk) {
        if (nodes_rdk == 0) {
            cout << "Graph is empty!\n";
            return;
        }

        bool visited_rdk[20] = {false};
        queue<int> q_rdk;

        visited_rdk[start_rdk] = true;
        q_rdk.push(start_rdk);

        cout << "BFS Traversal: ";

        while (!q_rdk.empty()) {
            int node_rdk = q_rdk.front();
            q_rdk.pop();
            cout << node_rdk << " ";

            for (int i = 0; i < nodes_rdk; i++) {
                if (adj_rdk[node_rdk][i] == 1 && !visited_rdk[i]) {
                    visited_rdk[i] = true;
                    q_rdk.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node_rdk, bool visited_rdk[]) {
        visited_rdk[node_rdk] = true;
        cout << node_rdk << " ";

        for (int i = 0; i < nodes_rdk; i++) {
            if (adj_rdk[node_rdk][i] == 1 && !visited_rdk[i]) {
                DFSUtil(i, visited_rdk);
            }
        }
    }

    void DFS(int start_rdk) {
        if (nodes_rdk == 0) {
            cout << "Graph is empty!\n";
            return;
        }

        bool visited_rdk[20] = {false};
        cout << "DFS Traversal: ";
        DFSUtil(start_rdk, visited_rdk);
        cout << endl;
    }
};

int main() {
    Graph g_rdk;
    int choice_rdk, start_rdk;

    while (true) {
        cout << "\n===== GRAPH MENU =====\n";
        cout << "1. Accept Graph (Adjacency Matrix)\n";
        cout << "2. Display Matrix\n";
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
                g_rdk.displayMatrix();
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

    Enter number of vertices: 4
    Enter adjacency matrix:
    0 1 1 0
    1 0 0 1
    1 0 0 1
    0 1 1 0
    Enter starting vertex: 0
    BFS: 0 1 2 3
    DFS: 0 1 3 2

## Dry Run (For BFS starting at 0)

-   Start = 0\
-   Visit 0 → enqueue neighbors 1, 2\
-   Visit 1 → enqueue neighbor 3\
-   Visit 2 → neighbor 3 already visited\
-   Visit 3 → done\
    Result: 0 1 2 3

## Conclusion

Graphs can be efficiently represented using adjacency matrices. BFS
explores nodes level-wise while DFS explores depth-wise. Both traversals
help in solving many real-world problems such as network traversal and
pathfinding.
