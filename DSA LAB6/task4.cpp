#include <iostream>
#include <string>
using namespace std;


class Patient {
public:
    string name;
    Patient* next;
    Patient(string n) {
        name = n;
        next = nullptr;
    }
};


class HospitalQueue {
private:
    Patient* head; 
public:
    HospitalQueue() { head = nullptr; }

    
    void AddPatient(string name) {
        Patient* newPatient = new Patient(name);
        if (!head) { head = newPatient; return; }
        Patient* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newPatient;
    }

    
    void RemovePatient(string name) {
        if (!head) return;
        if (head->name == name) {
            Patient* t = head;
            head = head->next;
            delete t;
            return;
        }
        Patient* temp = head;
        while (temp->next && temp->next->name != name) temp = temp->next;
        if (temp->next) {
            Patient* t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }
        else {
            cout << "Patient not found." << endl;
        }
    }

    
    void Display() {
        if (!head) { cout << "No patients in queue." << endl; return; }
        Patient* temp = head;
        cout << "Patients in queue: ";
        while (temp) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    
    int Count() {
        int count = 0;
        Patient* temp = head;
        while (temp) { count++; temp = temp->next; }
        return count;
    }
};


int main() {
    HospitalQueue queue;

    
    queue.AddPatient("Ali");
    queue.AddPatient("Sara");
    queue.AddPatient("Hamza");
    queue.Display();
    cout << "Total patients: " << queue.Count() << endl;

    
    queue.RemovePatient("Sara");
    queue.Display();
    cout << "Total patients: " << queue.Count() << endl;

    
    queue.RemovePatient("John");

    return 0;
}