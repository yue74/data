#include<iostream>
using namespace std;

template<typename T>
struct Treenode {
	T val;
	Treenode* left;
	Treenode* right;
	Treenode() :val(0),left(NULL),right(NULL){}
	Treenode(T x):val(x), left(NULL), right(NULL) {}
};

template<typename T>
class Tree {
private:
	Treenode<T>* nodes;//用顺序表来存储二叉树的结点
	Treenode<T>* root;
	size_t nodesize;
	Treenode<T>* create(T a[], int size, int nideid,T nullnode);//这个nullnode用于补全空结点的
	void visit(Treenode<T>* node);
	void preorder(Treenode<T>* node);
	void inorder(Treenode<T>* node);
	void postorder(Treenode<T>* node);
	//void levelorder(Treenode<T>* node);
public:
	Tree();
	Tree(int maxnodes);
	~Tree();
	Treenode<T>* getTreenode(int id);
	void createTree(T a[], int size, T nullnode);
	void preordertraversal();
	void inordertraversal();
	void postordertraversal();
	//void levelorder();
};

template<typename T>
Tree<T>::Tree() {
	nodesize = 100001;
	nodes = new Treenode<T>[nodesize];
}
template<typename T>
Tree<T>::Tree(int maxnodes) {
	nodesize = maxnodes;
	nodes = new Treenode<T>[nodesize];
}
template<typename T>
Tree<T>::~Tree() {
	delete[] nodes;
}
template<typename T>
Treenode<T>* Tree<T>::getTreenode(int id) {
	return &nodes[id];
}
template<typename T>
void Tree<T>::visit(Treenode<T>* node) {
	cout << node->val << endl;
}
template<typename T>
void Tree<T>::preorder(Treenode<T>* node) {
	if (node) {
		visit(node);
		preorder(node->left);//这个调用结束后回到一开始的时候去到right
		preorder(node->right);
	}
}
template<typename T>
void Tree<T>::inorder(Treenode<T>* node) {
	if (node) {
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}
template<typename T>
void Tree<T>::postorder(Treenode<T>* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}
template<typename T>
void Tree<T>::createTree(T a[], int size, T nullnode) {//这个nullnode在调用时再确定
	root = create(a, size, 1, nullnode);
}
template<typename T>
Treenode<T>* Tree<T>::create(T a[], int size, int nodeid, T nullnode) {
	if (nodeid >= size || a[nodeid] == nullnode) {
		return NULL;
	}
	Treenode<T>* nownode = getTreenode(nodeid);
	nownode->val = a[nodeid];
	nownode->left = create(a, size, nodeid * 2, nullnode);
	nownode->right = create(a, size, nodeid * 2 + 1, nullnode);
	return nownode;
}
template<typename T>
void Tree<T>::preordertraversal() {
	preorder(root);
}
template<typename T>
void Tree<T>::inordertraversal() {
	inorder(root);
}
template<typename T>
void Tree<T>::postordertraversal() {
	postorder(root);
}

int main() {
	const char nullnode = '-';
	char a[15] = {
		nullnode,'a','b','c','d',
		nullnode,'e','f','g','h',
		nullnode ,nullnode,nullnode,nullnode,'i'
	};
	Tree<char> t(15);
	t.createTree(a, 15, nullnode);
	t.preordertraversal(); cout << endl;
	t.inordertraversal(); cout << endl;
	t.postordertraversal(); cout << endl;

	 

}