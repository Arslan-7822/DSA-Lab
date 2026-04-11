#include <iostream>
#include <string>

using namespace std;

#define MAX 100


class Stack {
    int top;
    char arr[MAX];

public:
    Stack() { top = -1; }

    bool push(char x) {
        if (top >= (MAX - 1)) return false;
        arr[++top] = x;
        return true;
    }

    char pop() {
        if (top < 0) return 0;
        return arr[top--];
    }

    char peek() {
        if (top < 0) return 0;
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};


void reverseString(string input) {
    Stack s;
    for (int i = 0; i < input.length(); i++) {
        s.push(input[i]);
    }

    cout << "Reversed String: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}


bool isBalanced(string expr) {
    Stack s;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s.push('(');
        }
        else if (expr[i] == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }
    return s.isEmpty();
}


int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}


void infixToPostfix(string exp) {
    Stack s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            s.push('(');
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                result += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        result += s.pop();
    }
    cout << "Postfix Output: " << result << endl;
}

int main() {
    
    reverseString("Hello");

    
    string expr1 = "((a+b)*c)";
    cout << expr1 << " is " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;

    
    infixToPostfix("(a+b)*c");

    return 0;
}