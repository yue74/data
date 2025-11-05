#include<iostream>
using namespace std;

class gragh {
private:
	struct Edgenode {
		int vertex;//弧尾序号
		int weight;
		Edgenode* next;
	};
	struct Vertexnode {
		int vertex;//弧头
		Edgenode* firstedge;
	};
	int vertices;
	Vertexnode* nodes;
public:
	gragh(int vertices);
	~gragh();
	void addedge(int u, int v, int w);
	void printgragh();

};
gragh::gragh(int vertices) {
	this->vertices = vertices;
	nodes = new Vertexnode[vertices];
	for (int i = 0; i < vertices; ++i) {
		nodes[i].vertex = i;
		nodes[i].firstedge = NULL;
	}
 }
gragh::~gragh() {
	for (int i = 0; i < vertices; ++i) {
		Edgenode* curr = nodes[i].firstedge;
		while (curr) {
			Edgenode* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	delete[]nodes;
}
void gragh::addedge(int u, int v, int w) {//头插法
	Edgenode* newnode = new Edgenode;
	newnode->vertex = v;
	newnode->weight = w;
	newnode->next = nodes[u].firstedge;
	nodes[u].firstedge = newnode;
}

void gragh::printgragh() {
	for (int i = 0; i < vertices; ++i) {
		Edgenode* curr = nodes[i].firstedge;
		cout << "vertex" << i << ":";
		while (curr) {
			cout << curr->vertex << "(" << curr->weight << ")";
			curr = curr->next;
		}
		cout << endl;
	}
}
int main() {
	gragh g(5);
	g.addedge(0,1,4);
	g.addedge(0,2,2);
	g.addedge(1,2,3);
	g.addedge(2,3,4);
	g.addedge(3,4,2);
	g.printgragh();

	return 0;
}
