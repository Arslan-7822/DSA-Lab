//
//
//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//};
//
//// Create new node
//Node* createNode(int val) {
//	Node* n = new Node;
//	n->data = val;
//	n->left = n->right = NULL;
//	return n;
//}
//
//// Insert into BST (no duplicates)
//Node* insert(Node* root, int val) {
//	if (root == NULL)
//		return createNode(val);
//
//	if (val < root->data)
//		root->left = insert(root->left, val);
//	else if (val > root->data)
//		root->right = insert(root->right, val);
//
//	return root;
//}
//
//// Inorder
//void inorder(Node* root) {
//	if (root == NULL) return;
//	inorder(root->left);
//	cout << root->data << " ";
//	inorder(root->right);
//}
//
//// Preorder
//void preorder(Node* root) {
//	if (root == NULL) return;
//	cout << root->data << " ";
//	preorder(root->left);
//	preorder(root->right);
//}
//
//// Postorder
//void postorder(Node* root) {
//	if (root == NULL) return;
//	postorder(root->left);
//	postorder(root->right);
//	cout << root->data << " ";
//}
//
//// Search
//bool search(Node* root, int key) {
//	if (root == NULL) return false;
//
//	if (root->data == key) return true;
//	else if (key < root->data)
//		return search(root->left, key);
//	else
//		return search(root->right, key);
//}
//
//int main() {
//	Node* root = NULL;
//
//	int n;
//	cout << "Enter number of elements: ";
//	cin >> n;
//
//	cout << "Enter values: ";
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		root = insert(root, x);
//	}
//
//	cout << "\nInorder: ";
//	inorder(root);
//
//	cout << "\nPreorder: ";
//	preorder(root);
//
//	cout << "\nPostorder: ";
//	postorder(root);
//
//	int key;
//	cout << "\nEnter key to search: ";
//	cin >> key;
//
//	if (search(root, key))
//		cout << "Key found in BST\n";
//	else
//		cout << "Key not found in BST\n";
//
//	return 0;
//}