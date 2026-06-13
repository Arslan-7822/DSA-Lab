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
//Node* createNode(int val) {
//	Node* n = new Node;
//	n->data = val;
//	n->left = n->right = NULL;
//	return n;
//}
//
//Node* insert(Node* root, int val) {
//	if (root == NULL) return createNode(val);
//
//	if (val < root->data)
//		root->left = insert(root->left, val);
//	else if (val > root->data)
//		root->right = insert(root->right, val);
//
//	return root;
//}
//
//// Find minimum (inorder successor)
//Node* findMin(Node* root) {
//	while (root->left != NULL)
//		root = root->left;
//	return root;
//}
//
//// Delete node
//Node* deleteNode(Node* root, int key) {
//	if (root == NULL) return root;
//
//	if (key < root->data)
//		root->left = deleteNode(root->left, key);
//	else if (key > root->data)
//		root->right = deleteNode(root->right, key);
//	else {
//		// Case 1: no child
//		if (root->left == NULL && root->right == NULL) {
//			delete root;
//			return NULL;
//		}
//
//		// Case 2: one child
//		else if (root->left == NULL) {
//			Node* temp = root->right;
//			delete root;
//			return temp;
//		}
//		else if (root->right == NULL) {
//			Node* temp = root->left;
//			delete root;
//			return temp;
//		}
//
//		// Case 3: two children
//		Node* temp = findMin(root->right);
//		root->data = temp->data;
//		root->right = deleteNode(root->right, temp->data);
//	}
//
//	return root;
//}
//
//void inorder(Node* root) {
//	if (root == NULL) return;
//	inorder(root->left);
//	cout << root->data << " ";
//	inorder(root->right);
//}
//
//int main() {
//	Node* root = NULL;
//
//	int arr[] = { 50, 30, 70, 20, 40, 60, 80 };
//	int n = 7;
//
//	for (int i = 0; i < n; i++)
//		root = insert(root, arr[i]);
//
//	cout << "Before Deletion (Inorder): ";
//	inorder(root);
//
//	int key;
//	cout << "\nEnter value to delete: ";
//	cin >> key;
//
//	root = deleteNode(root, key);
//
//	cout << "After Deletion (Inorder): ";
//	inorder(root);
//
//	cout << endl;
//	return 0;
//}