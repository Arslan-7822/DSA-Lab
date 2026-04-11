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
                cout << "[" << temp->flightID << "] ";
                temp = temp->next;
            }
        }
    }
};

class RunwayController {
    FlightQueue emergencyQ;
    FlightQueue passengerQ;
    FlightQueue cargoQ;

public:
    
    void enqueueFlight(int type, string id) {
        if (type == 1) emergencyQ.enqueue(id);      
        else if (type == 2) passengerQ.enqueue(id); 
        else if (type == 3) cargoQ.enqueue(id);      
    }

    
    void dequeueFlight() {
        string landedID = "";
        string category = "";

        if (!emergencyQ.isEmpty()) {
            landedID = emergencyQ.dequeue();
            category = "Emergency";
        }
        else if (!passengerQ.isEmpty()) {
            landedID = passengerQ.dequeue();
            category = "Passenger";
        }
        else if (!cargoQ.isEmpty()) {
            landedID = cargoQ.dequeue();
            category = "Cargo";
        }

        if (landedID != "") {
            cout << "Now Landing: " << landedID << " (" << category << ")" << endl;
        }
        else {
            cout << "No flights waiting to land." << endl;
        }
    }

    // Task: display()
    void displayStatus() {
        cout << "\nEmergency Queue: "; emergencyQ.display();
        cout << "\nPassenger Queue: "; passengerQ.display();
        cout << "\nCargo Queue:     "; cargoQ.display();
        cout << "\n----------------------------" << endl;
    }
};

int main() {
    RunwayController runway;

    
    cout << "Incoming Flight Arrivals..." << endl;

    runway.enqueueFlight(2, "P1");
    runway.enqueueFlight(3, "C1");
    runway.enqueueFlight(1, "E1");
    runway.enqueueFlight(2, "P2");
    runway.enqueueFlight(3, "C2");
    runway.enqueueFlight(1, "E2");

    runway.displayStatus();

    cout << "\nStarting Runway Operations (Final Landing Order):" << endl;
    for (int i = 0; i < 6; i++) {
        runway.dequeueFlight();
    }

    return 0;
}