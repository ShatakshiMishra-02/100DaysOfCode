// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    Node* tail = head;
    int n = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    // Reduce k if greater than length
    k = k % n;
    if (k == 0)
        return head;

    // Make circular linked list
    tail->next = head;

    // Find new tail (n-k steps from head)
    Node* newTail = head;
    for (int i = 1; i < n - k; i++) {
        newTail = newTail->next;
    }

    // New head
    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    cin >> k;

    head = rotateRight(head, k);

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}