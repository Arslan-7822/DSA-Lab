//
//
//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//};
//
//void DFS(Node* root) {
//	if (root == NULL) return;
//
//	stack<Node*> s;
//	s.push(root);
//
//	while (!s.empty()) {
//		Node* current = s.top();
//		s.pop();
//
//		cout << current->data << " ";
//
//		// push right first so left is processed first
//		if (current->right != NULL)
//			s.push(current->right);
//
//		if (current->left != NULL)
//			s.push(current->left);
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
//	cout << "DFS Traversal: ";
//	DFS(root);
//	cout << endl;
//
//	return 0;
//}