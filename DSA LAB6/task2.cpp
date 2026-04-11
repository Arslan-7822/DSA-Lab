#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) { data = value; next = nullptr; }
};

class LinkedListADT {
private:
    Node* head;
public:
    LinkedListADT() { head = nullptr; }

    void InsertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void DeleteNode(int value) {
        if (!head) return;
        if (head->data == value) { Node* t = head; head = head->next; delete t; return; }
        Node* temp = head;
        while (temp->next && temp->next->data != value) temp = temp->next;
        if (temp->next) { Node* t = temp->next; temp->next = temp->next->next; delete t; }
        else cout << "Value not found." << endl;
    }

    void Display() {
        Node* temp = head;
        if (!temp) { cout << "List is empty." << endl; return; }
        cout << "List: ";
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedListADT list;
    list.InsertAtBeginning(30);
    list.InsertAtEnd(50);
    list.InsertAtBeginning(10);
    list.Display();

    list.DeleteNode(30);
    list.Display();
    return 0;
}