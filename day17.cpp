// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];

        if (arr[i] < minVal)
            minVal = arr[i];
    }

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    return 0;
}