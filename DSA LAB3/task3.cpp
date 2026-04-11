#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string arr[8];   
    int top;

public:
    myCarStack() {
        top = -1;
    }

    bool isFull() {
        return top == 7;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking is full\n";
            return;
        }
        top++;
        arr[top] = car;
        cout << "Car parked: " << car << endl;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        string temp = arr[top];
        top--;
        return temp;
    }

    string peek() {
        if (isEmpty()) return "";
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "No cars parked\n";
            return;
        }

        cout << "Cars in parking (top to bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    int count() {
        return top + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }
};

int main() {
    myCarStack parking, temp;

    int choice;
    string car;

    do {
        cout << "\n1. Park a car";
        cout << "\n2. Remove a car";
        cout << "\n3. Show parked cars";
        cout << "\n4. Total cars";
        cout << "\n5. Search car";
        cout << "\n6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
        }

        else if (choice == 2) {
            cout << "Enter car number to remove: ";
            cin >> car;

            if (parking.isEmpty()) {
                cout << "Parking is empty\n";
                continue;
            }

            if (!parking.search(car)) {
                cout << "Car not found\n";
                continue;
            }

            
            while (!parking.isEmpty() && parking.peek() != car) {
                temp.push(parking.pop());
            }

            
            if (!parking.isEmpty()) {
                cout << "Car removed: " << parking.pop() << endl;
            }

            
            while (!temp.isEmpty()) {
                parking.push(temp.pop());
            }
        }

        else if (choice == 3) {
            parking.display();
        }

        else if (choice == 4) {
            cout << "Total cars: " << parking.count() << endl;
        }

        else if (choice == 5) {
            cout << "Enter car number: ";
            cin >> car;

            if (parking.search(car))
                cout << "Car is in parking\n";
            else
                cout << "Car not found\n";
        }

    } while (choice != 6);

    return 0;
}