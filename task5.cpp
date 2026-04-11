#include <iostream>
#include <string>
using namespace std;


class Student {
public:
    string name;
    int priority; 
    Student* next;
    Student(string n, int p = 0) {
        name = n;
        priority = p;
        next = nullptr;
    }
};
class BookQueue {
private:
    Student* head; 
public:
    BookQueue() { head = nullptr; }

    
    void AddStudent(string name, int priority = 0) {
        Student* newStudent = new Student(name, priority);
        if (!head || head->priority < priority) { 
            newStudent->next = head;
            head = newStudent;
            return;
        }
        Student* temp = head;
        while (temp->next && temp->next->priority >= priority) temp = temp->next;
        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    
    void RemoveStudent(string name) {
        if (!head) return;
        if (head->name == name) { Student* t = head; head = head->next; delete t; return; }
        Student* temp = head;
        while (temp->next && temp->next->name != name) temp = temp->next;
        if (temp->next) { Student* t = temp->next; temp->next = temp->next->next; delete t; }
        else cout << "Student not found." << endl;
    }

    
    void Display() {
        if (!head) { cout << "No students in queue." << endl; return; }
        Student* temp = head;
        cout << "Reservation Queue: ";
        while (temp) { cout << temp->name << "(P:" << temp->priority << ") -> "; temp = temp->next; }
        cout << "NULL" << endl;
    }

    
    int Count() {
        int count = 0;
        Student* temp = head;
        while (temp) { count++; temp = temp->next; }
        return count;
    }

    
    void ServeNext() {
        if (!head) { cout << "Queue is empty, no student to serve.\n"; return; }
        cout << "Serving student: " << head->name << endl;
        Student* t = head;
        head = head->next;
        delete t;
    }

   
    void UpdatePriority(string name, int newPriority) {
        if (!head) return;
        Student* prev = nullptr;
        Student* temp = head;
        while (temp && temp->name != name) { prev = temp; temp = temp->next; }
        if (!temp) { cout << "Student not found.\n"; return; }
        
        if (prev) prev->next = temp->next;
        else head = temp->next;
        temp->next = nullptr;
        temp->priority = newPriority;
        
        if (!head || head->priority < newPriority) { temp->next = head; head = temp; return; }
        Student* t = head;
        while (t->next && t->next->priority >= newPriority) t = t->next;
        temp->next = t->next;
        t->next = temp;
    }
};


int main() {
    BookQueue book1, book2;

   
    book1.AddStudent("Ali", 1);
    book1.AddStudent("Sara", 2);
    book1.AddStudent("Hamza", 1);

    book2.AddStudent("Bilal");
    book2.AddStudent("Zara", 2);

    
    cout << "Book 1 queue:\n"; book1.Display();
    cout << "Book 2 queue:\n"; book2.Display();

    
    book1.ServeNext();
    cout << "Book 1 after serving next student:\n"; book1.Display();

    
    book1.UpdatePriority("Hamza", 3);
    cout << "Book 1 after updating Hamza's priority:\n"; book1.Display();

    
    book1.RemoveStudent("Hamza");
    cout << "Book 1 after removing Hamza:\n"; book1.Display();

    
    cout << "Total students in Book 1 queue: " << book1.Count() << endl;

    return 0;
}