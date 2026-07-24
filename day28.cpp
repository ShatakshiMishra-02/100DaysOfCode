// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a circular linked list
Node* createCircularList(int n) {
    if (n == 0)
        return nullptr;

    int x;
    cin >> x;
    Node* head = createNode(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        Node* newNode = createNode(x);
        tail->next = newNode;
        tail = newNode;
    }

    // Make the list circular
    tail->next = head;

    return head;
}

// Function to traverse and print the circular linked list
void traverseCircularList(Node* head) {
    if (head == nullptr)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    cin >> n;

    Node* head = createCircularList(n);

    traverseCircularList(head);

    return 0;
}