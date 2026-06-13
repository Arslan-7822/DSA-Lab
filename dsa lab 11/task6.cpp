

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct ExprNode {
	string data;
	ExprNode* left;
	ExprNode* right;
};

ExprNode* createNode(string val) {
	ExprNode* node = new ExprNode{ val, NULL, NULL };
	return node;
}

ExprNode* buildTree() {
	stack<ExprNode*> s;

	string postfix[] = { "3", "5", "+", "8", "2", "-", "*" };

	for (int i = 0; i < 7; i++) {
		string symbol = postfix[i];

		if (symbol == "+" || symbol == "-" || symbol == "*") {
			ExprNode* node = createNode(symbol);

			ExprNode* right = s.top(); s.pop();
			ExprNode* left = s.top(); s.pop();

			node->left = left;
			node->right = right;

			s.push(node);
		}
		else {
			s.push(createNode(symbol));
		}
	}

	return s.top();
}

int evaluate(ExprNode* root) {
	if (root->left == NULL && root->right == NULL)
		return stoi(root->data);

	int leftVal = evaluate(root->left);
	int rightVal = evaluate(root->right);

	if (root->data == "+") return leftVal + rightVal;
	if (root->data == "-") return leftVal - rightVal;
	if (root->data == "*") return leftVal * rightVal;

	return 0;
}

void printPrefix(ExprNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	printPrefix(root->left);
	printPrefix(root->right);
}

void printPostfix(ExprNode* root) {
	if (root == NULL) return;
	printPostfix(root->left);
	printPostfix(root->right);
	cout << root->data << " ";
}

void printInfix(ExprNode* root) {
	if (root == NULL) return;

	if (root->left && root->right) cout << "(";
	printInfix(root->left);
	cout << root->data;
	printInfix(root->right);
	if (root->left && root->right) cout << ")";
}

int main() {
	ExprNode* root = buildTree();

	cout << "Infix Expression: ";
	printInfix(root);
	cout << endl;

	cout << "Prefix Expression: ";
	printPrefix(root);
	cout << endl;

	cout << "Postfix Expression: ";
	printPostfix(root);
	cout << endl;

	cout << "Final Answer: " << evaluate(root) << endl;

	return 0;
}