// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        cin >> c >> e;

        Node* newNode = new Node;
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff;

        if (temp->exp > 1)
            cout << "x^" << temp->exp;
        else if (temp->exp == 1)
            cout << "x";

        if (temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    return 0;
}