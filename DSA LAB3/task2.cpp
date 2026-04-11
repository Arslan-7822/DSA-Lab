#include <iostream>
using namespace std;


template <class T>
class AbstractStack {
public:
    virtual void push(T val) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractStack() {}
};


template <class T>
class myStack : public AbstractStack<T> {
private:
    T* arr;       
    T* minArr;    
    int size;
    int topIndex;
    int minTop;

public:
    
    myStack(int s) {
        size = s;
        arr = new T[size];
        minArr = new T[size];
        topIndex = -1;
        minTop = -1;
    }

    
    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    
    void push(T val) {
        if (topIndex == size - 1) {
            cout << "Stack is full\n";
            return;
        }

        topIndex++;
        arr[topIndex] = val;

        
        if (minTop == -1 || val <= minArr[minTop]) {
            minTop++;
            minArr[minTop] = val;
        }
    }

    
    T pop() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return T();
        }

        T temp = arr[topIndex];

        if (temp == minArr[minTop]) {
            minTop--;
        }

        topIndex--;
        return temp;
    }

    
    T top() const {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[topIndex];
    }

    
    bool isEmpty() const {
        return topIndex == -1;
    }

    
    bool isFull() const {
        return topIndex == size - 1;
    }

    
    void display() const {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements:\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    T getMin() const {
        if (minTop == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return minArr[minTop];
    }
};


int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    myStack<int> s(n);

    int choice, val;

    do {
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Show top element";
        cout << "\n4. Check if stack is empty";
        cout << "\n5. Check if stack is full";
        cout << "\n6. Display stack";
        cout << "\n7. Show minimum element";
        cout << "\n8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
        }
        else if (choice == 2) {
            cout << "Popped: " << s.pop() << endl;
        }
        else if (choice == 3) {
            cout << "Top: " << s.top() << endl;
        }
        else if (choice == 4) {
            if (s.isEmpty())
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
        }
        else if (choice == 5) {
            if (s.isFull())
                cout << "Stack is full\n";
            else
                cout << "Stack is not full\n";
        }
        else if (choice == 6) {
            s.display();
        }
        else if (choice == 7) {
            cout << "Minimum element: " << s.getMin() << endl;
        }

    } while (choice != 8);

    return 0;
}