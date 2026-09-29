// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<float> arr(n);

    cout << "Enter elements between 0 and 1: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}