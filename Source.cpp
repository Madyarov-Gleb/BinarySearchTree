#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree<int> bst1;
	bst1.insertNode(7);
    bst1.insertNode(3);
    bst1.insertNode(9);
    bst1.insertNode(2);
    bst1.insertNode(5);
    bst1.insertNode(4);
    bst1.insertNode(8);
    bst1.insertNode(10);

    BinarySearchTree<int> bst2;
    bst2.insertNode(1);
    bst2.insertNode(2);
    bst2.insertNode(3);
    bst2.insertNode(4);
    bst2.insertNode(5);
    bst2.insertNode(6);
    bst2.insertNode(7);
    bst2.insertNode(8);

    cout << "--- Test Binary Search Tree ---" << endl;

    cout << endl << "bst1: ";
    bst1.output(cout);

    cout << endl << "bst2: ";
    bst2.output(cout);

    cout << endl << endl << "Search key 5 in bst1: " << (bst1.searchKeyIterative(9) ? "true" : "false");

    cout << endl << endl << "Insert key 11 in bst1: " << bst1.insertNode(11);
    cout << endl << "bst1: ";
    bst1.output(cout);

    cout << endl << endl << "Delete key 5 in bst1: " << bst1.deleteNode(5);
    cout << endl << "bst1: ";
    bst1.output(cout);

    cout << endl << endl << "bst1 number of nodes: " << bst1.getNumberOfNodes();
    cout << endl << "bst1 height: " << bst1.getHeight();

    cout << endl << endl << "Inorder walk of bst1 (iterative): ";
    bst1.inorderWalkIterative();

    cout << endl << "Inorder walk of bst1 (recursive): ";
    bst1.inorderWalk();

    cout << endl << "Walk by levels of bst1:" << endl;
    bst1.walkByLevels();

    cout << endl << "bst1 and bst2 are similar: " << (bst1.isSimilar(bst2) ? "true" : "false") << endl;

    cout << endl << "bst1 and bst2 have identical keys: " << (bst1.isIdenticalKey(bst2) ? "true" : "false") << endl;

	return EXIT_SUCCESS;
}