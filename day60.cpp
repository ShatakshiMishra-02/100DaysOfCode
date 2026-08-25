// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // Check Min-Heap property
    for (int i = 0; i < N; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Parent must be <= left child
        if (left < N && a[i] > a[left]) {
            cout << "NO";
            return 0;
        }

        // Parent must be <= right child
        if (right < N && a[i] > a[right]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}