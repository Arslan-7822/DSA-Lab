//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//struct Student {
//    int rollNumber;
//    string name;
//    float marks;
//    Student* next;
//};
//
//
//void insertAtBeginning(Student*& head);
//void insertAtEnd(Student*& head);
//void insertAfterRoll(Student* head);
//void deleteByRoll(Student*& head);
//void displayAll(Student* head);
//void searchByRoll(Student* head);
//void updateRecord(Student* head);
//void showStatistics(Student* head);
//void clearList(Student*& head);
//
//int main() {
//    Student* head = nullptr;
//    int choice;
//
//    while (true) {
//        cout << "\n----------------------------------";
//        cout << "\n STUDENT RECORD MANAGEMENT SYSTEM";
//        cout << "\n----------------------------------";
//        cout << "\n1. Insert at Beginning";
//        cout << "\n2. Insert at End";
//        cout << "\n3. Insert after a Specific Roll No";
//        cout << "\n4. Delete a Record";
//        cout << "\n5. Display All Records";
//        cout << "\n6. Search Student";
//        cout << "\n7. Update Record";
//        cout << "\n8. View Statistics";
//        cout << "\n9. Exit";
//        cout << "\nChoose an option (1-9): ";
//        cin >> choice;
//
//        if (choice == 9) break;
//
//        switch (choice) {
//        case 1: insertAtBeginning(head); break;
//        case 2: insertAtEnd(head); break;
//        case 3: insertAfterRoll(head); break;
//        case 4: deleteByRoll(head); break;
//        case 5: displayAll(head); break;
//        case 6: searchByRoll(head); break;
//        case 7: updateRecord(head); break;
//        case 8: showStatistics(head); break;
//        default: cout << "\nInvalid choice. Please try again.";
//        }
//    }
//
//    clearList(head); 
//    return 0;
//}
//
//
//
//void insertAtBeginning(Student*& head) {
//    Student* newNode = new Student;
//    cout << "Enter Roll Number, Name, Marks: ";
//    cin >> newNode->rollNumber >> newNode->name >> newNode->marks;
//
//    newNode->next = head;
//    head = newNode;
//    cout << "Record inserted successfully.\n";
//}
//
//void insertAtEnd(Student*& head) {
//    Student* newNode = new Student;
//    cout << "Enter Roll Number, Name, Marks: ";
//    cin >> newNode->rollNumber >> newNode->name >> newNode->marks;
//    newNode->next = nullptr;
//
//    if (head == nullptr) {
//        head = newNode;
//    }
//    else {
//        Student* temp = head;
//        while (temp->next != nullptr) temp = temp->next;
//        temp->next = newNode;
//    }
//    cout << "Record inserted successfully.\n";
//}
//
//void insertAfterRoll(Student* head) {
//    if (head == nullptr) {
//        cout << "List is empty.\n";
//        return;
//    }
//    int target;
//    cout << "Enter the Roll Number to insert after: ";
//    cin >> target;
//
//    Student* temp = head;
//    while (temp != nullptr && temp->rollNumber != target) temp = temp->next;
//
//    if (temp == nullptr) {
//        cout << "Roll Number " << target << " not found.\n";
//    }
//    else {
//        Student* newNode = new Student;
//        cout << "Enter New Roll Number, Name, Marks: ";
//        cin >> newNode->rollNumber >> newNode->name >> newNode->marks;
//        newNode->next = temp->next;
//        temp->next = newNode;
//        cout << "Record inserted successfully.\n";
//    }
//}
//
//void deleteByRoll(Student*& head) {
//    if (head == nullptr) {
//        cout << "List is empty.\n";
//        return;
//    }
//    int roll;
//    cout << "Enter Roll Number to delete: ";
//    cin >> roll;
//
//    Student* temp = head;
//    if (head->rollNumber == roll) {
//        head = head->next;
//        delete temp;
//        cout << "Record deleted.\n";
//        return;
//    }
//
//    Student* prev = nullptr;
//    while (temp != nullptr && temp->rollNumber != roll) {
//        prev = temp;
//        temp = temp->next;
//    }
//
//    if (temp == nullptr) {
//        cout << "Student not found.\n";
//    }
//    else {
//        prev->next = temp->next;
//        delete temp;
//        cout << "Record deleted.\n";
//    }
//}
//
//void displayAll(Student* head) {
//    if (head == nullptr) {
//        cout << "\nNo records available.";
//        return;
//    }
//    cout << "\nRoll\tName\t\tMarks\n";
//    cout << "--------------------------------\n";
//    Student* temp = head;
//    while (temp != nullptr) {
//        cout << temp->rollNumber << "\t" << temp->name << "\t\t" << temp->marks << endl;
//        temp = temp->next;
//    }
//}
//
//void searchByRoll(Student* head) {
//    int roll;
//    cout << "Enter Roll Number to search: ";
//    cin >> roll;
//    Student* temp = head;
//    while (temp != nullptr) {
//        if (temp->rollNumber == roll) {
//            cout << "Found: " << temp->name << " | Marks: " << temp->marks << endl;
//            return;
//        }
//        temp = temp->next;
//    }
//    cout << "Student not found.\n";
//}
//
//void updateRecord(Student* head) {
//    int roll;
//    cout << "Enter Roll Number to update: ";
//    cin >> roll;
//    Student* temp = head;
//    while (temp != nullptr) {
//        if (temp->rollNumber == roll) {
//            cout << "Current Name: " << temp->name << ", Marks: " << temp->marks << endl;
//            cout << "Enter New Name and Marks: ";
//            cin >> temp->name >> temp->marks;
//            cout << "Record updated.\n";
//            return;
//        }
//        temp = temp->next;
//    }
//    cout << "Student not found.\n";
//}
//
//void showStatistics(Student* head) {
//    if (head == nullptr) return;
//    float sum = 0, maxM = head->marks, minM = head->marks;
//    int count = 0;
//    Student* temp = head;
//    while (temp != nullptr) {
//        sum += temp->marks;
//        if (temp->marks > maxM) maxM = temp->marks;
//        if (temp->marks < minM) minM = temp->marks;
//        count++;
//        temp = temp->next;
//    }
//    cout << "\nAverage: " << (sum / count) << "\nHighest: " << maxM << "\nLowest: " << minM << endl;
//}
//
//void clearList(Student*& head) {
//    while (head != nullptr) {
//        Student* temp = head;
//        head = head->next;
//        delete temp;
//    }
//}