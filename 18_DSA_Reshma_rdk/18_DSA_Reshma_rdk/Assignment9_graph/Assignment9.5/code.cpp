/*Write a Program to accept a graph from a user and represent it with Adjacency List and perform 
BFS and DFS traversals on it.*/

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
