#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};

class DoublyLinkedList {
private:
	Node* head;

public:
	DoublyLinkedList() {
		head = NULL;
	}

	// Insert at end
	void insertEnd(int val) {
		Node* newNode = new Node(val);

		if (head == NULL) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
	}

	// Insert at start
	void insertStart(int val) {
		Node* newNode = new Node(val);

		if (head == NULL) {
			head = newNode;
			return;
		}

		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	// Insert at position (1-based index)
	void insertAtPosition(int val, int pos) {
		if (pos == 1) {
			insertStart(val);
			return;
		}

		Node* newNode = new Node(val);
		Node* temp = head;

		for (int i = 1; i < pos - 1 && temp != NULL; i++) {
			temp = temp->next;
		}

		if (temp == NULL) return;

		newNode->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = newNode;

		temp->next = newNode;
		newNode->prev = temp;
	}

	// Delete by value
	void deleteValue(int val) {
		if (head == NULL) return;

		Node* temp = head;

		// if first node
		if (temp->data == val) {
			head = temp->next;
			if (head != NULL)
				head->prev = NULL;
			delete temp;
			return;
		}

		while (temp != NULL && temp->data != val) {
			temp = temp->next;
		}

		if (temp == NULL) return;

		if (temp->next != NULL)
			temp->next->prev = temp->prev;

		if (temp->prev != NULL)
			temp->prev->next = temp->next;

		delete temp;
	}

	// Forward display
	void displayForward() {
		Node* temp = head;
		cout << "Forward: ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Reverse display
	void displayReverse() {
		if (head == NULL) return;

		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		cout << "Reverse: ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
};

int main() {
	DoublyLinkedList dll;

	dll.insertEnd(10);
	dll.insertEnd(20);
	dll.insertEnd(30);
	dll.insertStart(5);
	dll.insertAtPosition(15, 3);

	dll.displayForward();
	dll.displayReverse();

	dll.deleteValue(20);

	cout << "\nAfter Deletion:\n";
	dll.displayForward();
	dll.displayReverse();

	return 0;
}