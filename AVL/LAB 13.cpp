

#include <iostream>
using namespace std;

// Node structure
struct Node {
	int data;
	Node* left;
	Node* right;
};

// Create new node
Node* createNode(int val) {
	Node* n = new Node;
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// Insert in BST
Node* insert(Node* root, int val) {
	if (root == NULL)
		return createNode(val);

	if (val < root->data)
		root->left = insert(root->left, val);
	else if (val > root->data)
		root->right = insert(root->right, val);

	return root;
}

// Find minimum value node (for deletion case 2/3)
Node* findMin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

// Delete node from BST
Node* deleteNode(Node* root, int key) {
	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);

	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	else {
		// Case 1: No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// Case 2: One child
		else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		// Case 3: Two children
		Node* temp = findMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

// Inorder traversal
void inorder(Node* root) {
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	Node* root = NULL;

	int arr[] = { 50, 30, 70, 20, 40, 60, 80 };
	int n = 7;

	// Insert values
	for (int i = 0; i < n; i++) {
		root = insert(root, arr[i]);
	}

	cout << "After Insertion (In-order): ";
	inorder(root);
	cout << endl;

	// Delete value
	int del = 70;
	root = deleteNode(root, del);

	cout << "After Deletion (In-order): ";
	inorder(root);
	cout << endl;

	return 0;
}