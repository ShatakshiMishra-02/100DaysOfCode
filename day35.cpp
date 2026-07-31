// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) {
            return; // Queue Overflow
        }
        arr[++rear] = x;
    }

    void dequeue() {
        if (front > rear) {
            return; // Queue Underflow
        }
        front++;
    }

    void display() {
        if (front > rear) {
            cout << "Queue is Empty";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    q.display();

    return 0;
}