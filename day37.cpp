// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[1000];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int x) {
        int i = size - 1;

        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        size++;
    }

    void deleteElement() {
        if (size == 0) {
            cout << -1 << endl;
            return;
        }

        cout << arr[0] << endl;

        for (int i = 1; i < size; i++)
            arr[i - 1] = arr[i];

        size--;
    }

    void peek() {
        if (size == 0)
            cout << -1 << endl;
        else
            cout << arr[0] << endl;
    }
};

int main() {
    int N;
    cin >> N;

    PriorityQueue pq;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            pq.insert(x);
        }
        else if (op == "delete") {
            pq.deleteElement();
        }
        else if (op == "peek") {
            pq.peek();
        }
    }

    return 0;
}