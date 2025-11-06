#include<iostream>
using namespace std;
//哈希表是一种数据结构，通过哈希函数得到哈希值
// 散列关键字，值对应哈希值, 在哈希表的存储单元
// 哈希表地址对应哈希值在哈希表的存储位置
//哈希表映射关系（一个y对应一个x）雪崩效应

template<typename keytype,typename valtype>
class Hashnode {
public:
	keytype key;
	valtype val;
	Hashnode* next;
	Hashnode(const keytype& key, const valtype& val) {
		this->key = key;
		this->val = val;
		next = NULL;
	}
};

template<typename keytype, typename valtype>
class Hashtable {
private:
	int size;
	Hashnode< keytype,  valtype>** table;//指向每个桶元素的链表头
	//哈希函数
	int hash(const keytype& key)const {
		int hashkey = key % size;
		if (hashkey < 0) {
			hashkey += size; 	 
		}
		return hashkey;
	}
public:
	Hashtable(int size = 256);
	~Hashtable();
	void insert(const keytype& key, const valtype& val);
	void remove(const keytype& key);
	bool find(const keytype& key, valtype& val)const;
};

template<typename keytype, typename valtype>
Hashtable<keytype, valtype>::Hashtable(int size) {
	this->size = size;
	this->table = new Hashnode<keytype, valtype>* [size];
	for (int i = 0; i < size; ++i) {
		table[i] = NULL;
	}
}

template<typename keytype, typename valtype>
Hashtable<keytype,valtype>::~Hashtable(){
	for (int i = 0; i < size; ++i) {
		if (table[i]) {
			Hashnode<keytype, valtype>* curr = table[i];
			while (curr) {
				Hashnode<keytype, valtype>* temp = curr->next;
				delete curr;
				curr = temp;
				//Hashnode<keytype,valtype>*temp = curr;
				//curr = curr->next;
				//delete temp;
			}
			table[i] = NULL;
		}
	}
	delete[] table;
	table = NULL;
}

template<typename keytype, typename valtype>
void Hashtable<keytype,valtype>::insert(const keytype& key, const valtype& val) {
	int index = hash(key);
	Hashnode<keytype, valtype>* now = new Hashnode<keytype, valtype>(key, val);
	if (table[index] == NULL) {
		table[index] = now;
	}
	else {//头插法
		now->next = table[index];
		table[index] = now;
	}
}

template<typename keytype, typename valtype>
void Hashtable< keytype, valtype>::remove(const keytype& key) {
	int index = hash(key);
	if (table[index]) {
		if (table[index]->key == key) {
			Hashnode<keytype, valtype>* next = table[index]->next;
			delete table[index];
			table[index] = next;
		}
		else {
			Hashnode<keytype, valtype>* curr = table[index];
			while (curr->next && curr->next->key != key) {
				curr = curr->next;
			}
			if (curr->next) {
				Hashnode<keytype, valtype>* next = curr->next->next;
				delete curr->next;
				curr->next = next;
			}
		}
	}
	
}

template<typename keytype, typename valtype>
bool Hashtable< keytype,  valtype>::find(const keytype& key, valtype& val)const {
	int index = hash(key);
	if (table[index]) {
		if (table[index]->key == key) {
			val = table[index]->val;
			return true;
		}
		else {
			Hashnode<keytype, valtype>* curr = table[index];
			while (curr->next && curr->next->key != key) {
				curr = curr->next;
			}
			if (curr->next) {
				val = curr->next->val;
				return true;
			}
		}
	}
	return false;
}

int main() {
	
	return 0;
}