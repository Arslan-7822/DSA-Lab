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
    int size;
    int topIndex;

public:
    
    myStack(int s) {
        size = s;
        arr = new T[size];
        topIndex = -1;
    }

    
    ~myStack() {
        delete[] arr;
    }

    
    void push(T val) {
        if (topIndex == size - 1) {
            cout << "Stack is full\n";
        }
        else {
            topIndex++;
            arr[topIndex] = val;
        }
    }

    
    T pop() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        else {
            T temp = arr[topIndex];
            topIndex--;
            return temp;
        }
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
};


int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    myStack<int> s(n);

    int choice, val;

    do {
        cout << "\n1.Push\n2.Pop\n3.Top\n4.Check Empty\n5.Check Full\n6.Display\n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
        }
        else if (choice == 2) {
            cout << "Popped value: " << s.pop() << endl;
        }
        else if (choice == 3) {
            cout << "Top value: " << s.top() << endl;
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

    } while (choice != 7);

    return 0;
}