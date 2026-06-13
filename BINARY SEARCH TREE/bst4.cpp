

#include <iostream>
#include <string>
using namespace std;

// BST Node
struct Node {
	int data;        // ISBN
	string title;
	Node* left;
	Node* right;
};

// Linked List Node
struct LNode {
	int isbn;
	string title;
	LNode* next;
};

// Create BST node
Node* createBSTNode(int isbn, string title) {
	Node* n = new Node;
	n->data = isbn;
	n->title = title;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// Create Linked List node
LNode* createListNode(int isbn, string title) {
	LNode* n = new LNode;
	n->isbn = isbn;
	n->title = title;
	n->next = NULL;
	return n;
}

// Insert into BST
Node* insert(Node* root, int isbn, string title) {
	if (root == NULL)
		return createBSTNode(isbn, title);

	if (isbn < root->data)
		root->left = insert(root->left, isbn, title);
	else if (isbn > root->data)
		root->right = insert(root->right, isbn, title);

	return root;
}

// Linked list pointers
LNode* head = NULL;
LNode* tail = NULL;

// Convert BST to Linked List (Inorder)
void bstToList(Node* root) {
	if (root == NULL)
		return;

	bstToList(root->left);

	LNode* newNode = createListNode(root->data, root->title);

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}

	bstToList(root->right);
}

// Print linked list (SAFE for VS2013)
void printList() {
	LNode* temp = head;

	while (temp != NULL) {
		cout << temp->isbn;
		cout << " - ";
		cout << temp->title;
		cout << endl;

		temp = temp->next;
	}
}

int main() {
	Node* root = NULL;

	// Sample data (you can also take input if needed)
	root = insert(root, 50, "Book A");
	root = insert(root, 30, "Book B");
	root = insert(root, 70, "Book C");
	root = insert(root, 20, "Book D");
	root = insert(root, 40, "Book E");

	bstToList(root);

	cout << "Sorted Linked List (BST Converted):" << endl;
	printList();

	return 0;
}