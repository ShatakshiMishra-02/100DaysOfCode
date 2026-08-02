// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
    Node *front, *rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* temp = new Node;
        temp->data = value;

        if (front == NULL) {
            front = rear = temp;
            rear->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == NULL)
            return;

        if (front == rear) {
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (front == NULL)
            return;

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
    }
};

int main() {
    int n;
    cin >> n;

    CircularQueue q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        q.dequeue();
    }

    q.display();

    return 0;
}