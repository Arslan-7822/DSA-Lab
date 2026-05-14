#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void printlist(node* head)
{
   
    if (head == NULL)
    {
        return;
    }

   
    cout << head->data << " ";

  
    printlist(head->next);
}

int main()
{
    node* first = new node();
    node* second = new node();
    node* third = new node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    
    first->next = second;
    second->next = third;
    third->next = NULL;

  
    printlist(first);

    return 0;
}