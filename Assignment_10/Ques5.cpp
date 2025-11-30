#include <iostream>
using namespace std;

int adjP[100][100];
int key[100], parentP[100], mstSet[100];

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (enter 0 for no edge):\n";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adjP[i][j];

    for(int i = 1; i <= n; i++) {
        key[i] = 99999;
        mstSet[i] = 0;
    }

    key[1] = 0; 
    parentP[1] = -1;

    for(int i = 1; i <= n; i++) {
        int u = -1, minKey = 99999;

        for(int v = 1; v <= n; v++) {
            if(mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(adjP[u][v] && mstSet[v] == 0 && adjP[u][v] < key[v]) {
                key[v] = adjP[u][v];
                parentP[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    int sum = 0;

    for(int i = 2; i <= n; i++) {
        cout << parentP[i] << " -- " << i 
             << " weight: " << adjP[i][parentP[i]] << endl;
        sum += adjP[i][parentP[i]];
    }

    cout << "Total Weight = " << sum << endl;
    return 0;
}