#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        // Directed graph: u --> v
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int outDegree(int v) {
        return adjList[v].size();
    }

    int inDegree(int v) {
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (adjMatrix[i][v] == 1)
                count++;
        }
        return count;
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices to " << v << ": ";
        for (int node : adjList[v]) {
            cout << node << " ";
        }
        cout << endl;
    }

    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < V; i++) {
            count += adjList[i].size();
        }
        return count;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.displayAdjList();
    g.displayAdjMatrix();

    cout << "\nOut-degree of vertex 1: " << g.outDegree(1) << endl;
    cout << "In-degree of vertex 3: " << g.inDegree(3) << endl;

    g.adjacentVertices(1);

    cout << "\nTotal number of edges = " << g.numberOfEdges() << endl;

    return 0;
}
