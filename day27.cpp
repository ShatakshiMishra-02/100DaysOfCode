// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

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

// Insert node at end
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find length of linked list
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
int findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node *ptr1 = head1, *ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--)
            ptr1 = ptr1->next;
    } else {
        while (diff--)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n;

    Node* head1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(head1, x);
    }

    cin >> m;

    Node* head2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        insert(head2, x);
    }

    int ans = findIntersection(head1, head2);

    if (ans == -1)
        cout << "No Intersection";
    else
        cout << ans;

    return 0;
}