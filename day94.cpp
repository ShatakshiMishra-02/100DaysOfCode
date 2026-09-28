// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    // Find maximum element
    int maxi = *max_element(arr.begin(), arr.end());

    // Build frequency array
    vector<int> freq(maxi + 1, 0);
    for (int x : arr) {
        freq[x]++;
    }

    // Compute prefix sums
    for (int i = 1; i <= maxi; i++) {
        freq[i] += freq[i - 1];
    }

    // Build output array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[--freq[arr[i]]] = arr[i];
    }

    // Copy output to original array
    arr = output;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(arr);

    // Print sorted array
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}