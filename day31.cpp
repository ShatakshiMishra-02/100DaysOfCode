// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

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

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0)
                cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Stack s;

    while (n--) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int value;
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.display();
        }
    }

    return 0;
}