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
//// Check identical
//bool isIdentical(Node* r1, Node* r2) {
//	if (r1 == NULL && r2 == NULL)
//		return true;
//
//	if (r1 == NULL || r2 == NULL)
//		return false;
//
//	return (r1->data == r2->data &&
//		isIdentical(r1->left, r2->left) &&
//		isIdentical(r1->right, r2->right));
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
//	Node* root1 = NULL;
//	Node* root2 = NULL;
//
//	int arr1[] = { 50, 30, 70, 20, 40 };
//	int arr2[] = { 50, 30, 70, 20, 40 };
//
//	for (int i = 0; i < 5; i++) {
//		root1 = insert(root1, arr1[i]);
//		root2 = insert(root2, arr2[i]);
//	}
//
//	cout << "Tree 1 Inorder: ";
//	inorder(root1);
//
//	cout << "\nTree 2 Inorder: ";
//	inorder(root2);
//
//	if (isIdentical(root1, root2))
//		cout << "\nBSTs are identical\n";
//	else
//		cout << "\nBSTs are NOT identical\n";
//
//	return 0;
//}