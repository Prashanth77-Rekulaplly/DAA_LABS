#include <iostream>
#include <climits>
using namespace std;

const int V = 5;

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!mstSet[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V] = {false};

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !mstSet[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;

    cout << "Edge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << '\n';

        totalWeight += graph[i][parent[i]];
    }

    cout << "Total MST Weight: " << totalWeight << '\n';
}

int main()
{
    int graph[V][V] = {
        {0, 2, 3, 6, 0},
        {2, 0, 0, 4, 5},
        {3, 0, 0, 1, 7},
        {6, 4, 1, 0, 2},
        {0, 5, 7, 2, 0}
    };

    primMST(graph);

    return 0;
}