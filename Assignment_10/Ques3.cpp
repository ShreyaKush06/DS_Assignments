#include <iostream>
using namespace std;

int adj2[100][100];
int visited2[100];

void dfs(int node, int n) {
    visited2[node] = 1;
    cout << node << " ";

    for(int i = 1; i <= n; i++) {
        if(adj2[node][i] == 1 && visited2[i] == 0)
            dfs(i, n);
    }
}

int main() {
    int n, edges, u, v, start;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj2[u][v] = adj2[v][u] = 1;
    }

    cout << "Enter start node for DFS: ";
    cin >> start;

    dfs(start, n);
    return 0;
}