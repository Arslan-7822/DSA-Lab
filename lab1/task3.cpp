#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) { data = value; next = nullptr; }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void InsertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);
        if (pos == 1) { newNode->next = head; head = newNode; return; }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp) { cout << "Position out of range.\n"; delete newNode; return; }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void DeleteAtPosition(int pos) {
        if (!head) return;
        if (pos == 1) { Node* t = head; head = head->next; delete t; return; }
        Node* temp = head;
        for (int i = 1; temp->next && i < pos - 1; i++) temp = temp->next;
        if (!temp->next) { cout << "Position out of range.\n"; return; }
        Node* t = temp->next; temp->next = temp->next->next; delete t;
    }

    void Search(int value) {
        Node* temp = head; int pos = 1;
        while (temp) { if (temp->data == value) { cout << "Found at position " << pos << endl; return; } temp = temp->next; pos++; }
        cout << "Value not found." << endl;
    }

    int Count() {
        int c = 0; Node* temp = head;
        while (temp) { c++; temp = temp->next; }
        return c;
    }

    void Display() {
        Node* temp = head;
        if (!temp) { cout << "List empty.\n"; return; }
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << "\n1.Insert at position\n2.Delete at position\n3.Search\n4.Count\n5.Display\n0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value and position: "; cin >> value >> pos; list.InsertAtPosition(value, pos); break;
        case 2: cout << "Enter position to delete: "; cin >> pos; list.DeleteAtPosition(pos); break;
        case 3: cout << "Enter value to search: "; cin >> value; list.Search(value); break;
        case 4: cout << "Total nodes: " << list.Count() << endl; break;
        case 5: list.Display(); break;
        }
    } while (choice != 0);

    return 0;
}