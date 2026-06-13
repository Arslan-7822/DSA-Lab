//
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//};
//
//void BFS(Node* root) {
//	if (root == NULL) return;
//
//	queue<Node*> q;
//	q.push(root);
//
//	while (!q.empty()) {
//		Node* current = q.front();
//		q.pop();
//
//		cout << current->data << " ";
//
//		if (current->left != NULL)
//			q.push(current->left);
//
//		if (current->right != NULL)
//			q.push(current->right);
//	}
//}
//
//int main() {
//	Node* root = new Node{ 40, NULL, NULL };
//	Node* n20 = new Node{ 20, NULL, NULL };
//	Node* n60 = new Node{ 60, NULL, NULL };
//	Node* n10 = new Node{ 10, NULL, NULL };
//	Node* n30 = new Node{ 30, NULL, NULL };
//	Node* n50 = new Node{ 50, NULL, NULL };
//	Node* n70 = new Node{ 70, NULL, NULL };
//
//	root->left = n20;
//	root->right = n60;
//
//	n20->left = n10;
//	n20->right = n30;
//
//	n60->left = n50;
//	n60->right = n70;
//
//	cout << "BFS / Level-Order Traversal: ";
//	BFS(root);
//	cout << endl;
//
//	return 0;
//}