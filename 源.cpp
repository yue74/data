#include<iostream>
using namespace std;

template<typename T>
struct Listnode {//�����������洢�����
	T data;
	Listnode* next;
	Listnode(T d) :data(d), next(NULL){}
};

template<typename T>
struct Treenode {//����������洢data������ͷ
	T data;
	Listnode<Treenode<T>*> *childrenHead;
	Treenode() {
		childrenHead = NULL;
	}
	void AddChild(Treenode<T>* node) {//ͷ�巨��һ�����ӹ�ϵ��Ҫע�����˳��
		Listnode<Treenode<T>*>* childNode = new Listnode<Treenode<T>*> (node);//listnode��data���⽨����
		if (childrenHead == NULL) {
			childrenHead = childNode;
		}
		else {
			childNode->next = childrenHead;
			childrenHead = childNode;
		}
	}
};
template<typename T>
class Tree {//���Ľ����˳������洢�ģ�������������ʵ�ֵ�
private:
	Treenode<T>* nodes;
	Treenode<T>* root;
public:
	Tree();
	Tree(int masnodes);
	~Tree();
	Treenode<T>* GetTreenode(int id);
	void Setroot(int rootid);
	void Addchild(int parentid, int sonid);
	void Assigndata(int nodeid, T data);
	void Print(Treenode<T>* node = NULL);//�������
};

template<typename T>
Tree<T>::Tree() {
	nodes = new Treenode<T>[100001];
}

template<typename T>
Tree<T>::Tree(int maxnodes) {
	nodes = new Treenode<T>[maxnodes];
}

template<typename T>
Tree<T>::~Tree() {
	delete[] nodes;
}

template<typename T>
Treenode<T>* Tree<T>::GetTreenode(int id) {
	return &nodes[id];
} 

template<typename T>
void Tree<T>::Setroot(int rootid) {
	root = GetTreenode(rootid);
}

template<typename T>
void Tree<T>::Addchild(int parentid, int sonid) {//��ӱߵĹ�ϵ
	Treenode<T>* parentNode = GetTreenode(parentid);
	Treenode<T>* sonNode = GetTreenode(sonid);
	parentNode->AddChild(sonNode);
}

template<typename T>
void Tree<T>::Assigndata(int nodeid, T data){ //�Ǽ�
	GetTreenode(nodeid)->data = data;
}

template<typename T>
void Tree<T>::Print(Treenode<T>* node) {
	if (node == NULL) {
		node = root;
	}
	cout << node->data << endl;
	Listnode<Treenode<T>*>* temp = node->childrenHead;
	while (temp) {
		Print(temp->data);//temp��data��Treenode
		temp = temp->next;
	}
}


int main() {  
	Tree<char> t(9);
	t.Setroot(0);
	t.Assigndata(0, 'a');
	t.Assigndata(1, 'b');
	t.Assigndata(2, 'c');
	t.Assigndata(3, 'd');
	t.Assigndata(4, 'e');
	t.Assigndata(5, 'f');
	t.Assigndata(6, 'g');
	t.Assigndata(7, 'h');
	t.Assigndata(8, 'i');
	t.Addchild(0,2);
	t.Addchild(0,1);
	t.Addchild(1,3);
	t.Addchild(2,5);
	t.Addchild(2,4);
	t.Addchild(3,8);
	t.Addchild(3,7);
	t.Addchild(3,6);
	
	t.Print();


	return 0;
}