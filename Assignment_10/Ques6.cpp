#include <iostream>
using namespace std;

int adjD[100][100];
int distD[100];
int visitedD[100];

int main() {
    int n, start;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adjD[i][j];

    cout << "Enter source vertex: ";
    cin >> start;

    for(int i = 1; i <= n; i++) {
        distD[i] = 99999;
        visitedD[i] = 0;
    }

    distD[start] = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1;
        int minD = 99999;

        for(int v = 1; v <= n; v++)
            if(!visitedD[v] && distD[v] < minD)
                minD = distD[v], u = v;

        visitedD[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(adjD[u][v] && distD[u] + adjD[u][v] < distD[v])
                distD[v] = distD[u] + adjD[u][v];
        }
    }

    cout << "\nShortest distances from source:\n";
    for(int i = 1; i <= n; i++)
        cout << start << " -> " << i << " = " << distD[i] << endl;

    return 0;
}