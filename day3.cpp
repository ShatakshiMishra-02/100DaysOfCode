// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// Found at index 2
// Comparisons = 3

// Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int comparisons = 0;
    bool found = false;

    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            cout << "Found at index " << i << endl;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Not Found" << endl;
    }

    cout << "Comparisons = " << comparisons << endl;

    return 0;
}