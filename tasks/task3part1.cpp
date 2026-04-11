#include <iostream>
#include <string>

using namespace std;


struct Flight {
    string flightID;
    Flight* next;
};


struct FlightQueue {
    Flight* head = nullptr;
    Flight* tail = nullptr;

    bool isEmpty() {
        return head == nullptr;
    }

    
    void enqueue(string id) {
        Flight* newNode = new Flight;
        newNode->flightID = id;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    string dequeue() {
        if (isEmpty()) return "";
        Flight* temp = head;
        string id = temp->flightID;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        return id;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "[Empty]";
        }
        else {
            Flight* temp = head;
            while (temp != nullptr) {
                cout << "[" << temp->flightID << "] -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
};


class AirportController {
    FlightQueue emergencyQ;
    FlightQueue passengerQ;
    FlightQueue cargoQ;

public:
    void enqueueFlight(int type, string id) {
        if (type == 1) emergencyQ.enqueue(id);
        else if (type == 2) passengerQ.enqueue(id);
        else if (type == 3) cargoQ.enqueue(id);
        else cout << "Invalid flight category!\n";
    }

    void dequeueFlight() {
        string landedID = "";

        
        if (!emergencyQ.isEmpty()) {
            landedID = emergencyQ.dequeue();
            cout << "LANDING: " << landedID << " (Emergency)\n";
        }
        else if (!passengerQ.isEmpty()) {
            landedID = passengerQ.dequeue();
            cout << "LANDING: " << landedID << " (Passenger)\n";
        }
        else if (!cargoQ.isEmpty()) {
            landedID = cargoQ.dequeue();
            cout << "LANDING: " << landedID << " (Cargo)\n";
        }
        else {
            cout << "Runway is clear. No flights waiting.\n";
        }
    }

    void displayQueues() {
        cout << "\n--- CURRENT AIRPORT STATUS ---" << endl;
        cout << "Emergency Queue: "; emergencyQ.display(); cout << endl;
        cout << "Passenger Queue: "; passengerQ.display(); cout << endl;
        cout << "Cargo Queue:     "; cargoQ.display();     cout << endl;
        cout << "-----" << endl;
    }
};

int main() {
    AirportController tower;

    
    cout << "Incoming Flights Arriving..." << endl;
    tower.enqueueFlight(2, "P1");
    tower.enqueueFlight(3, "C1");
    tower.enqueueFlight(1, "E1");
    tower.enqueueFlight(2, "P2");
    tower.enqueueFlight(3, "C2");
    tower.enqueueFlight(1, "E2");

    tower.displayQueues();

    cout << "\nProcessing All Landings Based on Priority Rules:\n";
    for (int i = 0; i < 6; i++) {
        tower.dequeueFlight();
    }

    return 0;
}