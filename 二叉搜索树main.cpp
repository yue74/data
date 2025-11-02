#include<iostream>
using namespace std;
//×óÐ¡ÓÒ´ó
template<typename T>
struct Treenode {
	T val;
	Treenode* left;
	Treenode* right;
	Treenode() :val(0), left(NULL), right(NULL){}
	Treenode(T x) :val(x), left(NULL), right(NULL) {}
};
template<typename T>
class BinarySearchTree {
private:
	Treenode<T>* root;
	Treenode<T>* insertnode(Treenode<T>* node, T val);
	Treenode<T>* removenode(Treenode<T>* node, T val);
	bool searchnode(Treenode<T>* node, T val);
	void inorder(Treenode<T>* node);
public:
	BinarySearchTree() :root(NULL) {}
	~BinarySearchTree();
	void insert(T val) {
		root = insertnode(root, val);
	}
	void remove(T val) {
		root = removenode(root, val);
	}
	bool search(T val) {
		return searchnode(root, val);
	}
	void inordertravarsal() {
		inorder(root);
	}
};
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	while (root) {
		remove(root->val);
	}
}
template<typename T>
Treenode<T>* BinarySearchTree<T>::insertnode(Treenode<T>* node, T val) {
	if (node == NULL) {
		node = new Treenode<T>(val);
	}
	if (val < node->val) {
		node->left = insertnode(node->left,val);
	}
	else if (val > node->val) {
		node->right = insertnode(node->right, val);
	}
	return node;
}
template<typename T>
Treenode<T>* BinarySearchTree<T>::removenode(Treenode<T>* node, T val) {
	if (node == NULL) {
		return NULL;
	}
	if (val < node->val) {
		node->left = removenode(node->left, val);
	}
	else if (val > node->val) {
		node->right = removenode(node->right, val);
	}
	else {
		if (node->left == NULL &&node->right ==	NULL) {
			delete node;
		}
		else if (node->left == NULL) {
			Treenode<T>* rightchild = node->right;
			delete node;
			return rightchild;
		}
		else if(node->right == NULL) {
			Treenode<T>* leftchild = node->left;
			delete node;
			return leftchild;
		}
		else {
			Treenode<T>* replacement = node->right;
			while (replacement->left) {
				replacement = replacement->left;
			}
			node->val = replacement->val;
			node->right = removenode(node->right, replacement->val);
		}
	}
	return node;
}
template<typename T>
bool BinarySearchTree<T>::searchnode(Treenode<T>* node, T val) {
	if (node == NULL) {
		return false;
	}
	if (val < node->val) {
		return searchnode(node->left, val);
	}
	else if (val > node->val) {
		return searchnode(node->right, val);
	}
	return true;
}
template<typename T>
void BinarySearchTree<T>::inorder(Treenode<T>* node) {
	if (node) {
		inorder(node->left);
		cout << node->val << endl;
		inorder(node->right);
	}
}
int main() {

	BinarySearchTree<int> bst;
	bst.insert(5);
	bst.insert(4);
	bst.insert(3);
	bst.insert(6);
	bst.insert(1);
	bst.insert(2);
	bst.insert(2);
	bst.insert(2);
	bst.inordertravarsal();
	cout << bst.search(4) << endl;
	cout << bst.search(10) << endl;
	bst.remove(4);
	cout << bst.search(4) << endl;

	return 0;
}