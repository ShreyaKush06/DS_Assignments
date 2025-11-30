#include <iostream>
using namespace std;

int adj[100][100]; 
int visited[100];
int q[100], front = 0, rear = -1;

void bfs(int start, int n) {
    for(int i = 1; i <= n; i++)
        visited[i] = 0;

    q[++rear] = start;
    visited[start] = 1;

    while(front <= rear) {
        int node = q[front++];
        cout << node << " ";

        for(int i = 1; i <= n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
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
        adj[u][v] = adj[v][u] = 1;  
    }

    cout << "Enter start node for BFS: ";
    cin >> start;

    bfs(start, n);

    return 0;
}