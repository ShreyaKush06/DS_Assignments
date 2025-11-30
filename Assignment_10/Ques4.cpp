#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

Edge edges[100];
int parent[100];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for(int i = 1; i <= n; i++)
        parent[i] = i;

    cout << "Enter edges u v w:\n";
    for(int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for(int i = 0; i < e; i++) {
        for(int j = 0; j < e - i - 1; j++) {
            if(edges[j].w > edges[j+1].w)
                swap(edges[j], edges[j+1]);
        }
    }

    int mst_wt = 0;
    cout << "\nKruskal MST edges:\n";

    for(int i = 0; i < e; i++) {
        if(find(edges[i].u) != find(edges[i].v)) {
            cout << edges[i].u << " -- " << edges[i].v << "  weight: " 
                 << edges[i].w << endl;
            mst_wt += edges[i].w;
            unionSet(edges[i].u, edges[i].v);
        }
    }

    cout << "Total MST Weight = " << mst_wt << endl;
    return 0;
}