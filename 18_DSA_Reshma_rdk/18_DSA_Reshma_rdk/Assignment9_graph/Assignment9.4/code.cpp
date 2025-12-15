/*Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a 
user defined graph. Use Adjacency List to represent a graph.*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>

using namespace std;

class Graph {
    int nodes_rdk;
    vector<pair<int, int>> adj_rdk[50];   // node -> (neighbor, weight)

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

        for (int i = 0; i < nodes_rdk; i++)
            adj_rdk[i].clear();

        cout << "Enter edges as (u v weight):\n";
        for (int i = 0; i < edges_rdk; i++) {
            int u_rdk, v_rdk, w_rdk;
            cin >> u_rdk >> v_rdk >> w_rdk;

            adj_rdk[u_rdk].push_back({v_rdk, w_rdk});
            adj_rdk[v_rdk].push_back({u_rdk, w_rdk}); // undirected
        }

        cout << "Graph stored successfully.\n";
    }

    void dijkstra(int src_rdk, int dest_rdk) {
        if (nodes_rdk == 0) {
            cout << "Graph is empty!\n";
            return;
        }

        vector<int> dist_rdk(nodes_rdk, INT_MAX);
        vector<bool> visited_rdk(nodes_rdk, false);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq_rdk;

        dist_rdk[src_rdk] = 0;
        pq_rdk.push({0, src_rdk}); // (distance, node)

        while (!pq_rdk.empty()) {
            int node_rdk = pq_rdk.top().second;
            pq_rdk.pop();

            if (visited_rdk[node_rdk]) continue;
            visited_rdk[node_rdk] = true;

            for (auto &p : adj_rdk[node_rdk]) {
                int neigh_rdk = p.first;
                int weight_rdk = p.second;

                if (dist_rdk[node_rdk] + weight_rdk < dist_rdk[neigh_rdk]) {
                    dist_rdk[neigh_rdk] = dist_rdk[node_rdk] + weight_rdk;
                    pq_rdk.push({dist_rdk[neigh_rdk], neigh_rdk});
                }
            }
        }

        cout << "\nShortest distance from " << src_rdk
             << " to " << dest_rdk << " = " << dist_rdk[dest_rdk] << endl;
    }
};


int main() {
    Graph g_rdk;
    int choice_rdk, src_rdk, dest_rdk;

    while (true) {
        cout << "\n===== DIJKSTRA MENU =====\n";
        cout << "1. Accept Graph (Adjacency List)\n";
        cout << "2. Find Shortest Distance (Dijkstra)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                g_rdk.acceptGraph();
                break;

            case 2:
                cout << "Enter source node: ";
                cin >> src_rdk;
                cout << "Enter destination node: ";
                cin >> dest_rdk;
                g_rdk.dijkstra(src_rdk, dest_rdk);
                break;

            case 3:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
