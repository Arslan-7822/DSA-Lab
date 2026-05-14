#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* newNode(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void printList(Node* head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    printList(head->next);
}

Node* insertBegin(Node* head, int val)
{
    Node* temp = newNode(val);
    temp->next = head;
    return temp;
}

Node* insertEnd(Node* head, int val)
{
    if (head == NULL)
        return newNode(val);

    head->next = insertEnd(head->next, val);
    return head;
}

Node* insertPos(Node* head, int val, int pos)
{
    if (pos == 1)
    {
        Node* temp = newNode(val);
        temp->next = head;
        return temp;
    }

    if (head == NULL)
        return NULL;

    head->next = insertPos(head->next, val, pos - 1);
    return head;
}

Node* deleteValue(Node* head, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data == val)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, val);
    return head;
}

Node* deletePos(Node* head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 1)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletePos(head->next, pos - 1);
    return head;
}

int search(Node* head, int val, int pos)
{
    if (head == NULL)
        return -1;

    if (head->data == val)
        return pos;

    return search(head->next, val, pos + 1);
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 10);
    head = insertBegin(head, 5);
    head = insertEnd(head, 20);
    head = insertPos(head, 15, 3);

    cout << "List after insertions: ";
    printList(head);
    cout << endl;

    head = deleteValue(head, 5);
    cout << "After deleting value 5: ";
    printList(head);
    cout << endl;

    head = deletePos(head, 2);
    cout << "After deleting position 2: ";
    printList(head);
    cout << endl;

    int pos = search(head, 20, 1);
    cout << "Position of 20: " << pos << endl;

    return 0;
}