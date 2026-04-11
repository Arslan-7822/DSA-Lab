#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
    string arr[100];   
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(string val) {
        if (isFull()) {
            cout << "Stack full\n";
            return;
        }
        top++;
        arr[top] = val;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        string temp = arr[top];
        top--;
        return temp;
    }

    string peek() {
        if (isEmpty()) return "";
        return arr[top];
    }
};

int main() {
    Stack undoStack;
    Stack redoStack;

    string text = "";
    int choice;
    char ch;

    do {
        cout << "\n1. Type character";
        cout << "\n2. Delete last character";
        cout << "\n3. Undo";
        cout << "\n4. Redo";
        cout << "\n5. Show text";
        cout << "\n6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> ch;

            
            undoStack.push(text);

            text += ch;

            
            while (!redoStack.isEmpty())
                redoStack.pop();
        }

        else if (choice == 2) {
            if (text.length() == 0) {
                cout << "Nothing to delete\n";
                continue;
            }

            undoStack.push(text);

            text.pop_back();

            while (!redoStack.isEmpty())
                redoStack.pop();
        }

        else if (choice == 3) { 
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo\n";
                continue;
            }

            redoStack.push(text);

            text = undoStack.pop();
        }

        else if (choice == 4) { 
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo\n";
                continue;
            }

            undoStack.push(text);

            text = redoStack.pop();
        }

        else if (choice == 5) {
            cout << "Current text: " << text << endl;
        }

    } while (choice != 6);

    return 0;
}