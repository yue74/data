#include<iostream>
using namespace std;
#define inf -1

class gragh {
private:
    int vertices;
    int** edges;
public:
    gragh(int vertices);
    ~gragh();
    void addEdge(int u, int v, int w);
    void printgragh();

};
gragh::gragh(int vretices) {
    this->vertices = vretices;
    edges = new int* [vretices];
    for (int i = 0; i < vretices; ++i) {
        edges[i] = new int[vretices];
        for (int j = 0; j < vretices; ++j) {
            edges[i][j] = inf;
        }
    }
}
gragh::~gragh() {
    for (int i = 0; i < vertices; ++i) {
        delete[] edges[i];
    }
    delete[] edges;
}
void gragh::addEdge(int u, int v, int w){
    edges[u][v] = w;//可以优化为edges[u][v] = min(edges[u][v],w);
}
void gragh::printgragh() {
    for (int i = 0; i<vertices; ++i) {
        for (int j = 0; j < vertices; ++j) { 
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v = 5;
    gragh g(v);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 0, 4);
    g.addEdge(4, 2, 5);

    g.printgragh();

    return 0;

}
