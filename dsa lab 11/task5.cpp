//
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//struct ExprNode {
//	string data;
//	ExprNode* left;
//	ExprNode* right;
//};
//
//void printInfix(ExprNode* root) {
//	if (root == NULL) return;
//
//	if (root->left != NULL && root->right != NULL)
//		cout << "(";
//
//	printInfix(root->left);
//	cout << root->data;
//	printInfix(root->right);
//
//	if (root->left != NULL && root->right != NULL)
//		cout << ")";
//}
//
//void printPrefix(ExprNode* root) {
//	if (root == NULL) return;
//
//	cout << root->data << " ";
//	printPrefix(root->left);
//	printPrefix(root->right);
//}
//
//void printPostfix(ExprNode* root) {
//	if (root == NULL) return;
//
//	printPostfix(root->left);
//	printPostfix(root->right);
//	cout << root->data << " ";
//}
//
//int evaluate(ExprNode* root) {
//	if (root->left == NULL && root->right == NULL)
//		return stoi(root->data);
//
//	int leftVal = evaluate(root->left);
//	int rightVal = evaluate(root->right);
//
//	if (root->data == "+") return leftVal + rightVal;
//	if (root->data == "-") return leftVal - rightVal;
//	if (root->data == "*") return leftVal * rightVal;
//
//	return 0;
//}
//
//int main() {
//	ExprNode* root = new ExprNode{ "*", NULL, NULL };
//	ExprNode* plus = new ExprNode{ "+", NULL, NULL };
//	ExprNode* minus = new ExprNode{ "-", NULL, NULL };
//	ExprNode* n3 = new ExprNode{ "3", NULL, NULL };
//	ExprNode* n5 = new ExprNode{ "5", NULL, NULL };
//	ExprNode* n8 = new ExprNode{ "8", NULL, NULL };
//	ExprNode* n2 = new ExprNode{ "2", NULL, NULL };
//
//	root->left = plus;
//	root->right = minus;
//
//	plus->left = n3;
//	plus->right = n5;
//
//	minus->left = n8;
//	minus->right = n2;
//
//	cout << "Infix Expression: ";
//	printInfix(root);
//	cout << endl;
//
//	cout << "Prefix Expression: ";
//	printPrefix(root);
//	cout << endl;
//
//	cout << "Postfix Expression: ";
//	printPostfix(root);
//	cout << endl;
//
//	cout << "Evaluation: " << evaluate(root) << endl;
//
//	return 0;
//}