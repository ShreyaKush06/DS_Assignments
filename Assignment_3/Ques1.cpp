#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements are:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 4:
            cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 5:
            stack.display();
            break;
        case 6:
            stack.peek();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
