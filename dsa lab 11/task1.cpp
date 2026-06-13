//
//
//#include <iostream>
//using namespace std;
//
//// Node structure
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//};
//
//// Function to print leaf nodes
//void printLeafNodes(Node* root) {
//	if (root == NULL) return;
//
//	if (root->left == NULL && root->right == NULL) {
//		cout << root->data << " ";
//		return;
//	}
//
//	printLeafNodes(root->left);
//	printLeafNodes(root->right);
//}
//
//int main() {
//	// Creating nodes manually
//	Node* root = new Node{ 40, NULL, NULL };
//	Node* n20 = new Node{ 20, NULL, NULL };
//	Node* n60 = new Node{ 60, NULL, NULL };
//	Node* n10 = new Node{ 10, NULL, NULL };
//	Node* n30 = new Node{ 30, NULL, NULL };
//	Node* n50 = new Node{ 50, NULL, NULL };
//	Node* n70 = new Node{ 70, NULL, NULL };
//
//	// Linking nodes
//	root->left = n20;
//	root->right = n60;
//
//	n20->left = n10;
//	n20->right = n30;
//
//	n60->left = n50;
//	n60->right = n70;
//
//	// Output
//	cout << "Root Node: " << root->data << endl;
//	cout << "Left Child of Root: " << root->left->data << endl;
//	cout << "Right Child of Root: " << root->right->data << endl;
//
//	cout << "Leaf Nodes: ";
//	printLeafNodes(root);
//	cout << endl;
//
//	return 0;
//}