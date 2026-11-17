#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

bool unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU == rootV) {
        return false;
    }

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }

    return true;
}

int main() {
    int n, e;

    cout << "Enter number of vertices and edges: ";
    if (!(cin >> n >> e) || n <= 0 || e < 0) {
        cerr << "Invalid number of vertices or edges.\n";
        return 1;
    }

    vector<Edge> edges(e);

    cout << "Enter edges (u v weight), with vertices numbered 0 to "
         << n - 1 << ":\n";

    for (Edge& edge : edges) {
        cin >> edge.u >> edge.v >> edge.weight;

        if (!cin || edge.u < 0 || edge.u >= n || edge.v < 0 || edge.v >= n) {
            cerr << "Invalid edge input.\n";
            return 1;
        }
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    iota(parent.begin(), parent.end(), 0);

    long long totalWeight = 0;
    int edgeCount = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (const Edge& edge : edges) {
        if (unionSet(edge.u, edge.v, parent, rank)) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << '\n';
            totalWeight += edge.weight;
            edgeCount++;

            if (edgeCount == n - 1) {
                break;
            }
        }
    }

    if (edgeCount != n - 1) {
        cout << "Graph is disconnected. MST not possible.\n";
    } else {
        cout << "Total MST weight: " << totalWeight << '\n';
    }

    return 0;
}