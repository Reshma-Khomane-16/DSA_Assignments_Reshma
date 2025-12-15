/*Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent a graph.*/

#include <iostream>
#include <vector>
#include <queue>
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

        cout << "Enter edges in format: source destination weight\n";
        for (int i = 0; i < edges_rdk; i++) {
            int u_rdk, v_rdk, w_rdk;
            cin >> u_rdk >> v_rdk >> w_rdk;

            adj_rdk[u_rdk].push_back({v_rdk, w_rdk});
            adj_rdk[v_rdk].push_back({u_rdk, w_rdk}); // undirected
        }

        cout << "Graph stored successfully.\n";
    }

    void displayGraph() {
        if (nodes_rdk == 0) {
            cout << "Graph empty!\n";
            return;
        }

        cout << "\nAdjacency List:\n";
        for (int i = 0; i < nodes_rdk; i++) {
            cout << i << " -> ";
            for (auto p : adj_rdk[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }

    void primMST(int start_rdk) {
        if (nodes_rdk == 0) {
            cout << "Graph empty!\n";
            return;
        }

        vector<bool> visited_rdk(nodes_rdk, false);
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>> > pq_rdk;

        // (weight, (from, to))
        pq_rdk.push({0, {-1, start_rdk}});

        int mstWeight_rdk = 0;

        cout << "\nEdges in MST:\n";

        while (!pq_rdk.empty()) {
            auto top_rdk = pq_rdk.top();
            pq_rdk.pop();

            int wt_rdk = top_rdk.first;
            int from_rdk = top_rdk.second.first;
            int to_rdk = top_rdk.second.second;

            if (visited_rdk[to_rdk]) 
                continue;

            visited_rdk[to_rdk] = true;
            mstWeight_rdk += wt_rdk;

            if (from_rdk != -1)
                cout << from_rdk << " --(" << wt_rdk << ")--> " << to_rdk << endl;

            for (auto &p : adj_rdk[to_rdk]) {
                int neigh_rdk = p.first;
                int w_rdk = p.second;

                if (!visited_rdk[neigh_rdk]) {
                    pq_rdk.push({w_rdk, {to_rdk, neigh_rdk}});
                }
            }
        }

        cout << "\nTotal Minimum Cost = " << mstWeight_rdk << endl;
    }
};


int main() {
    Graph g_rdk;
    int choice_rdk, start_rdk;

    while (true) {
        cout << "\n===== PRIM'S MST MENU =====\n";
        cout << "1. Accept Graph (Adjacency List)\n";
        cout << "2. Display Graph\n";
        cout << "3. Find MST using Prim's Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
                g_rdk.primMST(start_rdk);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
