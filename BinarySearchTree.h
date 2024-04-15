#pragma once
#include <iostream>
#include "StackArray.h"
#include "QueueArray.h"
using namespace std;

template <class T>
class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;
	BinarySearchTree <T>& operator = (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator = (BinarySearchTree <T>&& src) noexcept;
	virtual ~BinarySearchTree();

	bool searchKeyIterative(const T& key) const ;
	bool insertNode(const T& key);
	bool deleteNode(const T& key);
	void output(std::ostream& out) const;
	int getNumberOfNodes() const;
	int getHeight() const;
	void inorderWalkIterative() const;
	void inorderWalk() const;
	void walkByLevels() const;
	bool isSimilar(const BinarySearchTree<T>& other) const;
	bool isIdenticalKey(const BinarySearchTree<T>& other) const;
private:
	template <class T>
	struct Node {
		T key_;
		Node<T>* left_;
		Node<T>* right_;
		Node(T key, Node* left = nullptr, Node* right = nullptr) : key_(key), left_(left), right_(right) {}
	};
	Node<T>* searchNodeIterative(const T& key) const;
	void output(std::ostream& out, Node<T>* root) const;
	int getNumberOfNodes(const Node<T>* node) const;
	int getHeight(const Node<T>* node) const;
	void inorderWalk(Node<T>* node) const;
	bool isSimilar(Node<T>* root1, Node<T>* root2) const;
	bool isIdenticalKey(Node<T>* root1, Node<T>* root2) const;
	Node<T>* root_;
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {};

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr) noexcept {
	root_ = scr.root_;
	scr.root_ = nullptr;
}

template <class T>
BinarySearchTree <T>& BinarySearchTree<T>::operator =(BinarySearchTree <T>&& src) noexcept {
	if (this != &src) {
		delete root_;
		root_ = src.root_;
		src.root_ = nullptr;
	}
	return *this;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	delete root_;
}

template <class T>
bool BinarySearchTree<T>::searchKeyIterative(const T& key) const {
	Node<T>* current = root_;
	while (current != nullptr) {
		if (key == current->key_) {
			return true;
		}
		else if (key < current->key_) {
			current = current->left_;
		}
		else {
			current = current->right_;
		}
	}
	return false;
}

template <class T>
bool BinarySearchTree<T>::insertNode(const T& key) {
	Node<T>* parent = root_;
	Node<T>* current = root_;
	while (current != nullptr) {
		if (key == current->key_) {
			return false;
		}
		else if (key < current->key_) {
			parent = current;
			current = current->left_;
		}
		else {
			parent = current;
			current = current->right_;
		}
	}
	Node<T>* newNode = new Node<T>(key);
	if (parent == nullptr) {
		root_ = newNode;
	}
	else if (key < parent->key_) {
		parent->left_ = newNode;
	}
	else {
		parent->right_ = newNode;
	}
	return true;
}

template <class T>
bool BinarySearchTree<T>::deleteNode(const T& key) {
	Node<T>* parent = root_;
	Node<T>* current = root_;
	while (current != nullptr && current->key_ != key) { // наверно ||
		parent = current;
		if (key < current->key_) {
			current = current->left_;
		}
		else {
			current = current->right_;
		}
	}
	if (current == nullptr) {
		return false;
	}
	Node<T>* successor = nullptr;
	if (current->left_ == nullptr || current->right_ == nullptr) {
		if (current->left_ == nullptr) {
			successor = current->right_;
		}
		else {
			successor = current->left_;
		}
		if (parent == nullptr) {
			root_ = successor;
		}
		else if (current == parent->left_) {
			parent->left_ = successor;
		}
		else {
			parent->right_ = successor;
		}
	}
	else {
		Node<T>* successorParent = current;
		successor = current->right_;
		while (successor->left_ != nullptr) {
			successorParent = successor;
			successor = successor->left_;
		}
		if (successorParent != current) {
			successorParent->left_ = successor->right_;
			successor->right_ = current->right_;
		}
		successor->left_ = current->left_;
		if (parent == nullptr) {
			root_ = successor;
		}
		else if (current == parent->left_) {
			parent->left_ = successor;
		}
		else {
			parent->right_ = successor;
		}
	}
	current->left_ = nullptr;
	current->right_ = nullptr;
	delete current;
	return true;
}

template <class T>
void BinarySearchTree<T>::output(std::ostream& out) const {
	output(out, root_);
}

template <class T>
void BinarySearchTree<T>::output(std::ostream& out, Node<T>* root) const {
	if (root == nullptr) {
		return;
	}
	out << "(";
	output(out, root->left_);
	out << root->key_;
	output(out, root->right_);
	out << ")";
}

template <class T>
int BinarySearchTree<T>::getNumberOfNodes() const{
	return getNumberOfNodes(root_);
}

template <class T>
int BinarySearchTree<T>::getNumberOfNodes(const Node<T>* node) const {
	if (node == nullptr) {
		return 0;
	}
	return 1 + getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_);
}

template <class T>
int BinarySearchTree<T>::getHeight() const {
	return getHeight(root_);
}

template <class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const {
	if (node == nullptr) {
		return -1;
	}
	return 1 + max(getHeight(node->left_), getHeight(node->right_));
}

template <class T>
void BinarySearchTree<T>::inorderWalkIterative() const {
	StackArray<Node<T>*> nodes(1000);
	Node<T>* current = root_;
	while (current != nullptr || !nodes.isEmpty()) {
		while (current != nullptr) {
			nodes.push(current);
			current = current->left_;
		}
		current = nodes.Top();
		nodes.pop();
		cout << current->key_ << " ";
		current = current->right_;
	}
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::inorderWalk() const {
	inorderWalk(root_);
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const {
	if (node == nullptr) {
		return;
	}
	inorderWalk(node->left_);
	cout << node->key_ << " ";
	inorderWalk(node->right_);
}

template <class T>
void BinarySearchTree<T>::walkByLevels() const {
	QueueArray<Node<T>*> levels(1000);
	levels.enQueue(root_);
	while (!levels.isEmpty()) {
		int count = levels.getSize();
		while (count > 0) {
			Node<T>* current = levels.Head();
			levels.deQueue();
			cout << current->key_ << " ";
			if (current->left_ != nullptr) {
				levels.enQueue(current->left_);
			}
			if (current->right_ != nullptr) {
				levels.enQueue(current->right_);
			}
			count--;
		}
		cout << endl;
	}
}

template <class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& other) const {
	return isSimilar(root_, other.root_);
}

template <class T>
bool BinarySearchTree<T>::isSimilar(Node<T>* root1, Node<T>* root2) const {
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}
	if (root1 == nullptr || root2 == nullptr) {
		return false;
	}
	return isSimilar(root1->left_, root2->left_) && isSimilar(root1->right_, root2->right_);
}

template <class T>
bool BinarySearchTree<T>::isIdenticalKey(const BinarySearchTree<T>& other) const {
	return isIdenticalKey(root_, other.root_);
}

template <class T>
bool BinarySearchTree<T>::isIdenticalKey(Node<T>* root1, Node<T>* root2) const {
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}
	if (root1 == nullptr || root2 == nullptr) {
		return false;
	}
	if (root1->key_ == root2->key_) {
		return true;
	}
	return isIdenticalKey(root1->left_, root2->left_) || isIdenticalKey(root1->right_, root2->right_);
}